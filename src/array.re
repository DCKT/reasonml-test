type person = {
  age: int,
  name: string
};

let logUserDescription = (user: person) =>
  print_string(String.concat(" ", [user.name, string_of_int(user.age)]));

let thomas = {age: 25, name: "Thomas"};

let julie = {age: 24, name: "Julie"};

let victor = {age: 4, name: "Victor"};

let martin = {age: 2, name: "Martin"};

let family = [thomas, julie, victor, martin];

let adults = List.filter(({age}) => age > 18, family);

let y = List.map(user => {...user, age: user.age + 1}, family);

List.filter(({age}) => age > 18, family)
|> (filterAdults => List.iter(logUserDescription, filterAdults));