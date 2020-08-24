const express = require('express')
const app = express()
const port = 3000
const { User } = require('./models/User');
const bodyParser = require('body-parser');
const cookieParser = require('cookie-parser');
const config = require('./config/key');

//application/x-www-form-urlencoded 형태로 된 데이터를 분석해서 가져올 수 있게 하는 옵션
app.use(bodyParser.urlencoded({extended: true}));
//application/json
app.use(bodyParser.json());

const mongoose = require('mongoose');
mongoose.connect(config.mongoURI, {
	useNewUrlParser : true, useUnifiedTopology : true, useCreateIndex : true, useFindAndModify : false
}).then(() => console.log("MongoDB connected..."))
  .catch(err => console.log("Error"))

app.get('/', (req, res) => {
  res.send('Hello World!')
})

app.post('/register', (req, res) => {
  const user = new User(req.body)
  user.save((err, userInfo) => {
	if(err) return res.json({ success : false, err})
	return res.status(200).json({ success : true })
  })
})

//request를 하면 response가 있어야 한다
app.post('/login', (req, res) => {
	//요청된 이메일이 데이터베이스에 있는지 확인
	User.findOne({email: req.body.email}, (err, userInfo) => {
		if(!userInfo) {
			return res.json({
				loginSuccess : false, 
				message : "제공된 이메일에 해당하는 유저가 없습니다."
			})
		}
		//있다면 비밀번호가 같은지 확인
		userInfo.comparePassword(req.body.password, (err, isMatch) => {
			if(!isMatch)
				return res.json({ loginSuccess : false, message : "비밀번호가 틀렸습니다."})
			//비밀번호까지 맞다면 토큰을 생성하기
			userInfo.generateToken((err, user) => { //파라미터 user는 user.save()함수에서 cb로 받아온 user값
				if(err) return res.status(400).send(err);
				//token을 저장한다. 어디에? 쿠키, 로컬 스토리지, 세션 등에 저장 가능
				res.cookie("x_auth", user.token)
					.status(200)
					.json({ loginSuccess : true, userId : user._id})
			})
		})
	})
	

})


app.listen(port, () => {
  console.log(`Example app listening at http://localhost:${port}`)
})
