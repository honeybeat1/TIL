var template = {
	HTML : function (title, list, body, control){
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
			${control}
			${body}
		</body>
		</html>
		`;
	}, list : function (filelist){
		var list = '<ul>'; //여는 태그로 시작해서
		var i = 0;
		while (i < filelist.length){
			list = list + `<li><a href="/?id=${filelist[i]}">${filelist[i]}</a></li>`;
			i++;
		}
		list = list + '</ul>'; //닫히는 태그로 마무리
		return list;
	}
}

module.exports = template;
