/* import styles */
// [%bs.raw {|require('./style/rc.css')|}];

// [%bs.raw {|require('./style/app.css')|}];

// [%bs.raw {|require('./style/nprogress.css')|}];

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  let currentPage = switch (url.path) {
  | [] => <Home />
  | ["search", search] => <Search search />
  | ["user", user] => <User user />
  | _ => <NotFound />
  };

  <div className="rc-typography"> <Nav /> currentPage </div>

};