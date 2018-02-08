type nodeCallback;

module Encoding = {
  type norm =
    | HEX
    | UTF8
    | ASCII
    | LATIN1
    | BASE64;
  let getNorm = (e: norm) =>
    switch e {
    | UTF8 => "utf8"
    | HEX => "hex"
    | ASCII => "ascii"
    | LATIN1 => "latin1"
    | BASE64 => "base64"
    };
};

let dirname: option(string) = [%bs.node __dirname];

[@bs.module "path"] external resolve : (string, string) => 'path = "resolve";

[@bs.module "fs"]
external fsReadFile : ('test, string, 'callback) => 'nodeCallback = "readFile";

let readFile = (path: string, norm: Encoding.norm, callback) =>
  fsReadFile(path, Encoding.getNorm(norm), callback);

switch dirname {
| None => print_endline("no __dirname")
| Some(path) =>
  readFile(resolve(path, "test.txt"), UTF8, (err, data) =>
    Js.to_bool(err) ? print_endline("Error") : print_endline("Ok")
  )
};