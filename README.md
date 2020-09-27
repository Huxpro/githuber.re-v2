# [Githuber.RE V2](https://huangxuan.me/githuber.re-v2/)

Get Started:

```sh
$ npm install

$ npm run start # bsb -make-world

# in another terminal tab
$ npm run dev  # start dev server
# noted that the `moduleseve --spa` used by bsb template seem to be broken.
```

This project demonstrates the following tech stack:

## [🐫 ReasonML](https://reasonml.github.io/)

Reason is a statically-typed, functional programming language backing by OCaml.

It leverage both the JavaScript & OCaml ecosystems by providing a familiar syntax geared toward JavaScript programmers and by catering to the existing NPM/Yarn workflow folks already know.

## [⚛️ ReasonReact](https://reasonml.github.io/reason-react/en/) with Functional APIs and Hooks.

ReasonReact is Reason's official binding to [React.js](https://reactjs.org/). By leveraging the Reason's built-in language features, it pack React.js' APIs into one that is statically-typed, simple, familiar and feels "Just using Reason".

This project used the latest [Function APIs with Hooks](https://reasonml.github.io/reason-react/blog/2019/04/10/react-hooks) and updated built-in [Router API](https://reasonml.github.io/reason-react/docs/en/router).

## [🕸 Graph_PPX](https://github.com/reasonml-community/graphql_ppx)

GraphQL_PPX is a syntax extension for BuckleScript/Reason. It make constructing GraphQL queries in Reason a first-class experience and type-safe, with compile time type check instead of runtime errors.

This project used the BS/Reason version of GraphQL from under `reasonml-community`. The [mhallin's](https://github.com/mhallin/graphql_ppx) version used by V1 does not build with OCaml 4.06 unfortunately.

## [📦 BuckleScript](https://bucklescript.github.io/)

BuckleScript is a compiler and toolchain that transforms OCaml/Reason into readable JavaScript code. It comes with a powerful API to talk to JS, allowing you to access the latter's vast ecosystem.

This project used its `bsb` build system for generated intial project templates. Checkout [ReasonReact installation](https://reasonml.github.io/reason-react/docs/en/installation#bucklescript) for more details.

## [🐙 Github GraphQL API](https://developer.github.com/v4/)

[Github announced its public APIs v4 that supports GraphQL](https://githubengineering.com/the-github-graphql-api/). Thanks to that, we can play and demonstrate GraphQL's power without the ceremoies of building our own API server. 


