[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  // It's known that we didn't handle the case when the app is hosted under a
  // basename. As a result, routing on <huangxuan.me/githuber.re-v2> is broken.
  let currentPage =
    switch (url.path) {
    | [] => <Home />
    | ["serch", search] => <Search search />
    | ["user", user] => <User user />
    | _ => <NotFound />
    };

  <div className="rc-typography"> <Nav /> currentPage </div>;
};
