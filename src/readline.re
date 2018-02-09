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

Random.self_init();

let numberFound = ref(false);

let mysteryNumber = Random.int(10);

let rl: Node.Readline.interface =
  Node.Readline.createInterface({
    "input": Node.process##stdin,
    "output": Node.process##stdout
  });

[@bs.val]
external question : (string, Node.callback) => option(string) = "rl.question";

external close : option(unit) => option(string) = "rl.close";

let handleString = (text: string) =>
  switch (int_of_string(text)) {
  | exception (Failure("int_of_string")) =>
    print_endline("This is not a number")
  | int when int > mysteryNumber => print_endline("It's less !")
  | int when int < mysteryNumber => print_endline("It's more !")
  | int => print_endline("Congrats !")
  };

let rec play = () =>
  question("Found the mystery number [0-10] : ", answer =>
    switch answer {
    | None => print_endline("You must write value")
    | Some(text) => handleString(text)
    }
  );

play();