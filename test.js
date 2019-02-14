const con = require('./');

console.log('isVisible: %O', con.isVisible());
con.hide();
console.log('isVisible: %O', con.isVisible());
con.show();
console.log('isVisible: %O', con.isVisible());
