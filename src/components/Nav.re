[@react.component]
let make = () => {
  let searchRef = React.useRef(Js.Nullable.null);

  let onSearch = event => {
    event->ReactEvent.Form.preventDefault;
    switch (searchRef.current->Js.toOption) {
    | None => ()
    | Some(eleRef) =>
      let ele = ReactDOMRe.domElementToObj(eleRef);
      switch (ele##value) {
      | "" => ()
      | searchVal =>
        ReasonReactRouter.push("/search/" ++ searchVal);
        ele##value #= "";
        ele##blur();
      };
    };
  };

  <div className="rc-navbar app-navbar">
    <h1 onClick={_ => ReasonReactRouter.push("/")}>
      {ReasonReact.string("Githuber.RE")}
    </h1>
    <form className="flex" onSubmit=onSearch>
      <input
        type_="search"
        ref={ReactDOMRe.Ref.domRef(searchRef)}
        placeholder="Search someone"
      />
      <button className="rc-button"> {React.string("Go")} </button>
    </form>
  </div>;
};