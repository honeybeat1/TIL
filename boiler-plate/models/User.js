//유저 모델에서 => 화살표함수 사용하지 않는 이유
//화살표 함수는 this를 바인딩 하지 않아서 User의 다큐멘트를 가질 수 없다

const mongoose = require('mongoose');
const bcrypt = require('bcrypt');
const saltRounds = 10;
const jwt = require('jsonwebtoken');

const userSchema = mongoose.Schema({
	name: {
		type : String,
		maxlength : 5
	},
	email: {
		type : String,
		trim : true,
		unique : 1
	},
	password: {
		type : String,
		minlength : 5
	},
	lastname: {
		type : String,
		maxlength : 50
	},
	role: {
		type : Number,
		default: 0
	},
	image : String,
	token : {
		type : String
	},
	tokenExp : {
		type : Number
	}
})

userSchema.pre('save', function(next){
	var user = this;
	//password가 수정된 경우에만
	if(user.isModified('password')) {
	//비밀번호를 암호화 시킨다
		bcrypt.genSalt(saltRounds, function(err, salt){
			if(err) return next(err) //에러가 나면 바로 save메소드로 보내라
			bcrypt.hash(user.password, salt, function(err, hash){
			if(err) return next(err)
			user.password = hash
			next()
			})
		})
	}
	else {
		next()
	}
})

//login하는 부분에 있는 함수 comparePassword 정의
userSchema.methods.comparePassword = function(plainPassword, cb){ //cb는 (err, isMatch)임
	//plainPassword 123456  암호화된 비밀번호 $2b$10$6xrG3PghXIdrw0AhhIbGP.JWh6q6UvBOhz5HzKQooWM7DSAaK5yGC
	//bcrypt의 compare함수를 이용하여 user가 입력한 pwd와 비교한 후 결과를 isMatch(boolean)에 담아준다
	bcrypt.compare(plainPassword, this.password, function(err, isMatch){
		if(err) return cb(err); //비밀번호가 같지 않다 
		cb(null, isMatch); //isMatch == true
	})
}

//generateToken method 정의
userSchema.methods.generateToken = function(cb){//콜백 펑션 하나만 들어있음

	var user = this;
	//jsonwebtoken을 이용해서 token을 생성하기
	var token = jwt.sign(user._id.toHexString(), 'secretToken');
	//user._id + 'secretToken' = token
	user.token = token
	//userSchema token 필드에 방금 만든 token 넣기
	user.save(function(err, user){
		if(err) return cb(err)
		cb(null, user)
	})
}



const User = mongoose.model('User', userSchema)
module.exports = { User }
