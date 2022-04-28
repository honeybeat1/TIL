var http = require('http');
var fs = require('fs');
var url = require('url');
var qs = require('querystring');
var template = require('./lib/template.js');

				/*
				var list = `<ul>
					<li><a href="/?id=HTML">HTML</a></li>
					<li><a href="/?id=CSS">CSS</a></li>
					<li><a href="/?id=JavaScript">JavaScript</a></li>
				</ul>`;
				*/


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
				var list = template.list(filelist);
				var html = template.HTML(title, list,`<h2>${title}</h2>${description}`,
				`<a href="/create">create</a>`);
				response.writeHead(200);
				response.end(html); //원하는 정보 출력
			})
		} else {
			fs.readdir('./data', function(err, filelist){				
				fs.readFile(`data/${title}`, 'utf8', function(err, description){
					var list = template.list(filelist);
					var html = template.HTML(title, list,
						`<h2>${title}</h2>${description}`,
						` <a href="/create">create</a>
						  <a href="/update?id=${title}">update</a>
						  <form action="delete_process" method="post">
							  <input type="hidden" name="id" value="${title}">
							  <input type="submit" value="delete">
						  </form>`
					); 
					response.writeHead(200);
					response.end(html);
					});
				}
			)}
	} else if(pathname === '/create'){
		fs.readdir('./data', function(err, filelist){
			var title = 'Web - Create';
			var list = template.list(filelist);
			var html = template.HTML(title, list,`
				<form action="/create_process" method="post"> 
					<p>
						<input type="text" name="title" placeholder="title">
					</p>
					<p>
						<textarea name="description" placeholder="description"></textarea>
					</p>
					<p>
						<input type="submit">
					</p>
				</form>
			`, '');
			response.writeHead(200);
			response.end(html);
		});
	} else if(pathname === '/create_process'){
		var body = '';
		//조각 조각 가져오기
		request.on('data', function(data){
			body += data;
		})
		//정보 수신이 다 넘어왔을 때
		request.on('end', function(){
			var post = qs.parse(body);
			var title = post.title;
			var description = post.description;
			fs.writeFile(`data/${title}`, description, 'utf8', function(err){
				response.writeHead(302, {Location : `/?id=${title}`});
				response.end();
			})
		})	
	} else if(pathname === '/update'){
		fs.readdir('./data', function(err, filelist){				
			fs.readFile(`data/${title}`, 'utf8', function(err, description){
				var list = template.list(filelist);
				var html = template.HTML(title, list,
					`
					<form action="/update_process" method="post"> 
						<p><input type="hidden" name="id" value ="${title}">
						<p><input type="text" name="title" placeholder="title" value="${title}"></p>
						<p><textarea name="description" placeholder="description">${description}</textarea></p>
						<p><input type="submit"></p>
					</form>
					`,	
					`<a href="/create">create</a> <a href="/update?id=${title}">update</a>`
				); 
				response.writeHead(200);
				response.end(html);
				});
		});
	} else if(pathname === '/update_process'){
		var body = '';
		request.on('data', function(data){
			body += data;
		})
		request.on('end', function(){
			var post = qs.parse(body);
			var title = post.title;
			var description = post.description;
			var id = post.id;
			fs.rename(`data/${id}`, `data/${title}`, function(err){
				//제목 바꿨으니 내용도 바꿉시다
				fs.writeFile(`data/${title}`, description, 'utf8', function(err){
					response.writeHead(302, {Location : `/?id=${title}`});
					response.end();
				});
			});
		})
	} else if(pathname === '/delete_process'){
		var body = '';
		request.on('data', function(data){
			body += data;
		});
		request.on('end', function(){
			var post = qs.parse(body);
			var id = post.id;
			fs.unlink(`data/${id}`, function(err){
				response.writeHead(302, {Location: '/'});
				response.end();
			});
		});
	}  else {
		response.writeHead(404);
		response.end('Not Found');
	}
});
app.listen(3000);
