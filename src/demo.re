[@bs.deriving jsConverter]
type fruit = [ | `Apple | `Kiwi | `Watermelon];

let appleString = fruitToJs(`Apple); /* "Apple" */

let kiwiString = fruitToJs(`Kiwi); /* "miniCoconut" */

print_endline(appleString);