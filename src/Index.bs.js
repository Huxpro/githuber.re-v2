'use strict';

var React = require("react");
var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");

ReactDOMRe.renderToElementWithId(React.createElement("div", undefined, "Hello World"), "root");

/*  Not a pure module */
