var fs = require('fs');

console.log('A');
fs.readFile('sample.txt','utf8', function(err, data){
	console.log(data);
});
console.log('C');
//var result = fs.readFileSync('sample.txt', 'utf-8');
//console.log(result);
