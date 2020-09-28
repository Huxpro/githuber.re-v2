// If the expected basename occured, strip it out from the path.
// This is to handle cases when the app is hosted under `/github.re-v2/`.
let stripBasename = (path) => {
  switch(path) {
  | ["githuber.re-v2", ...path] => path
  | path => path
  }
};

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  let currentPage =
    switch (stripBasename(url.path)) {
    | [] => <Home />
    | ["search", search] => <Search search />
    | ["user", user] => <User user />
    | _ => <NotFound />
    };

  <div className="rc-typography"> <Nav /> currentPage </div>;
};
