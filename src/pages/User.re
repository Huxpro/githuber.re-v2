module UserQuery = [%graphql
  {|
    query($login: String!) {
      user(login: $login){
        id
        url
        bio
        name
        login
        avatarUrl
        followers {
          totalCount
        }
        following {
          totalCount
        }
      }
    }
  |}
];

let renderShell =
  <div className="rc-box app-user app-container"> <img alt="" /> </div>;

[@react.component]
let make = (~user) => {
  let (data: option(UserQuery.t), setData) = React.useState(() => None);

  let renderNotFound =
    <div className="app-container">
      <h4 className="rc-box"> {React.string("Hmm...we found no one")} </h4>
    </div>;

  // fetch data
  React.useEffect1(
    () => {
      UserQuery.make(~login=user, ())
      |> Api.sendQuery
      |> Js.Promise.then_(resp => {
           Js.log(resp);
           setData(_ => Some(resp));
           Js.Promise.resolve();
         })
      |> ignore;
      None;
    },
    // refetch only when user changes
    [|user|],
  );

  switch (data) {
  | None => renderShell
  | Some(data) =>
    switch (data##user) {
    | None => renderNotFound
    | Some(data) =>
      let name = data##name->Belt.Option.getWithDefault("");
      let bio = data##bio->Belt.Option.getWithDefault("");
      let url =
        Js.Json.decodeString(data##url)->Belt.Option.getWithDefault("");
      let avatarUrl =
        Js.Json.decodeString(data##avatarUrl)
        ->Belt.Option.getWithDefault("");
      <div className="rc-box app-user app-container">
        <img src=avatarUrl alt=name />
        <h3> <a href=url> {React.string(name)} </a> </h3>
        <h5> {React.string(data##login)} </h5>
        <h5> {React.string(bio)} </h5>
        <section className="rc-typography--caption-large">
          {React.string("FOLLOWING")}
          <h3>
            {string_of_int(data##following##totalCount)->React.string}
          </h3>
        </section>
        <section className="rc-typography--caption-large">
          {React.string("FOLLOWERS")}
          <h3>
            {string_of_int(data##followers##totalCount)->React.string}
          </h3>
        </section>
      </div>;
    }
  };
};