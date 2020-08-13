var http = require('http');
var fs = require('fs');
var url = require('url');

				/*
				var list = `<ul>
					<li><a href="/?id=HTML">HTML</a></li>
					<li><a href="/?id=CSS">CSS</a></li>
					<li><a href="/?id=JavaScript">JavaScript</a></li>
				</ul>`;
				*/

function templateHTML(title, list, body){
	return `
	<!doctype html>
	<html>
	<head>
		<title>WEB1 - ${title}</title>
		<meta charset="utf-8">
	</head>
	<body>
		<h1><a href="/">WEB</a></h1>
		${list}
		${body}
	</body>
	</html>
	`;
}

function templateList(filelist){
	var list = '<ul>'; //여는 태그로 시작해서
	var i = 0;
	while (i < filelist.length){
		list = list + `<li><a href="/?id=${filelist[i]}">${filelist[i]}</a></li>`;
		i++;
	}
	list = list + '</ul>'; //닫히는 태그로 마무리
	return list;
}

var app = http.createServer(function(request,response){
	var _url = request.url;
	var queryData = url.parse(_url, true).query;
	var title = queryData.id;
	var pathname = url.parse(_url, true).pathname;
    
	if(pathname === '/'){
		if (title === undefined){
			fs.readdir('./data', function(err, filelist){
				var title = 'Welcome';
				var description = "Hello, Node.js";
				var list = templateList(filelist);
				var template = templateHTML(title, list,`<h2>${title}</h2>${description}`);
				response.writeHead(200);
				response.end(template); //원하는 정보 출력
			})
		} else {
			fs.readdir('./data', function(err, filelist){				
				fs.readFile(`data/${title}`, 'utf8', function(err, description){
					var list = templateList(filelist);
					var template = templateHTML(title, list,`<h2>${title}</h2>${description}`); 
					response.writeHead(200);
					response.end(template);
					});
				}
			)}
	} else {
		response.writeHead(404);
		response.end('Not Found');
	}
});
app.listen(3000);
