// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var List       = require("bs-platform/lib/js/list.js");
var $$String   = require("bs-platform/lib/js/string.js");
var Pervasives = require("bs-platform/lib/js/pervasives.js");

function logUserDescription(user) {
  return Pervasives.print_string($$String.concat(" ", /* :: */[
                  user[/* name */1],
                  /* :: */[
                    Pervasives.string_of_int(user[/* age */0]),
                    /* [] */0
                  ]
                ]));
}

var thomas = /* record */[
  /* age */25,
  /* name */"Thomas"
];

var julie = /* record */[
  /* age */24,
  /* name */"Julie"
];

var victor = /* record */[
  /* age */4,
  /* name */"Victor"
];

var martin = /* record */[
  /* age */2,
  /* name */"Martin"
];

var family_001 = /* :: */[
  julie,
  /* :: */[
    victor,
    /* :: */[
      martin,
      /* [] */0
    ]
  ]
];

var family = /* :: */[
  thomas,
  family_001
];

var adults = List.filter((function (param) {
          return +(param[/* age */0] > 18);
        }))(family);

var y = List.map((function (user) {
        return /* record */[
                /* age */user[/* age */0] + 1 | 0,
                /* name */user[/* name */1]
              ];
      }), family);

var filterAdults = List.filter((function (param) {
          return +(param[/* age */0] > 18);
        }))(family);

List.iter(logUserDescription, filterAdults);

exports.logUserDescription = logUserDescription;
exports.thomas             = thomas;
exports.julie              = julie;
exports.victor             = victor;
exports.martin             = martin;
exports.family             = family;
exports.adults             = adults;
exports.y                  = y;
/* adults Not a pure module */
