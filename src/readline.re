module Node = {
  type callback = option(string) => unit;
  type nodeProcess = {
    .
    "stdin": string,
    "stdout": string
  };
  let process: nodeProcess = [%bs.raw {| process |}];
  module Readline = {
    type currentProcess = {
      .
      "input": string,
      "output": string
    };
    type interface = {
      question: (string, callback) => option(string),
      close: option(unit) => option(unit)
    };
    [@bs.module "readline"]
    external createInterface : currentProcess => interface = "createInterface";
  };
};

let rl: Node.Readline.interface =
  Node.Readline.createInterface({
    "input": Node.process##stdin,
    "output": Node.process##stdout
  });

[@bs.val]
external question : (string, Node.callback) => option(string) = "rl.question";

external close : option(unit) => option(string) = "rl.close";

question("Test : ", answer =>
  switch answer {
  | None => print_endline("You must write value")
  | Some(text) => print_endline("ok this text ==> " ++ text)
  }
);