module SearchQuery = [%graphql
  {|
    query($username: String!) {
      search(query: $username, type:USER, first: 10) {
        pageInfo {
          hasNextPage
          hasPreviousPage
          endCursor
        }
        userCount
        nodes {
          ...on User{
            id
            login
            avatarUrl
          }
        }
      }
    }
  |}
];

/*
 type iSearchResultItem = [
   | `Nonexhaustive
   | `User(
       {
         .
         "avatarUrl": Js.Json.t,
         "id": string,
         "login": string,
       },
     )
 ];
 */
let renderList = nodes =>
  switch (nodes) {
  | None => assert(false) /* Empty nodes shouldn't pass usercount check */
  | Some(nodes) =>
    nodes
    |> Js.Array.map(node =>
         switch (node) {
         | None => ReasonReact.null
         | Some(node) =>
           switch (node) {
           | `Nonexhaustive => ReasonReact.null
           | `User(user) =>
             let avatarUrl =
               switch (Js.Json.decodeString(user##avatarUrl)) {
               | None => assert(false)
               | Some(url) => url
               };
             <li
               className="rc-list-item"
               key=user##id
               onClick={_ => ReasonReactRouter.push("/user/" ++ user##login)}>
               <img src=avatarUrl alt=user##login />
               <span className="rc-list-item__text">
                 {React.string(user##login)}
               </span>
             </li>;
           }
         }
       )
    |> ReasonReact.array
  };

let renderNotFound =
  <div className="app-container">
    <h4 className="rc-box"> {React.string("Hmm...we found no one")} </h4>
  </div>;

[@react.component]
let make = (~search) => {
  let (data: option(SearchQuery.t), setData) = React.useState(() => None);

  // fetch data
  React.useEffect1(
    () => {
      SearchQuery.make(~username=search, ())
      |> Api.sendQuery
      |> Js.Promise.then_(resp => {
           Js.log(resp);
           setData(_ => Some(resp));
           Js.Promise.resolve();
         })
      |> ignore;
      None;
    },
    // refetch only when search changes
    [|search|],
  );

  switch (data) {
  | None => ReasonReact.null
  | Some(data) =>
    if (data##search##userCount == 0) {
      renderNotFound;
    } else {
      <ul className="rc-list app-container">
        <h4
          className="rc-box"
          style={ReactDOMRe.Style.make(~marginBottom="0", ())}>
          {ReasonReact.string("Top Results - " ++ search)}
        </h4>
        {renderList(data##search##nodes)}
      </ul>;
    }
  };
};