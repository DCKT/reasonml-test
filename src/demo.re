type nodeProcess = {
  .
  "stdin": string,
  "stdout": string
};

let process: nodeProcess = [%bs.raw {| process |}];

type currentProcess = {
  .
  "input": string,
  "output": string
};

type callback = option(string) => unit;

type interface = {
  question: (string, callback) => option(string),
  close: option(unit) => option(unit)
};

[@bs.module "readline"]
external createInterface : currentProcess => interface = "createInterface";

let rl: interface =
  createInterface({"input": process##stdin, "output": process##stdout});

rl.question("Test", answer =>
  switch answer {
  | None => print_endline("You must write value")
  | Some(text) => print_endline("ok this text" ++ text)
  }
);