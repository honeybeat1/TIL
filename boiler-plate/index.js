const express = require('express')
const app = express()
const port = 3000
const { User } = require('./models/User');
const bodyParser = require('body-parser');

//application/x-www-form-urlencoded 형태로 된 데이터를 분석해서 가져올 수 있게 하는 옵션
app.use(bodyParser.urlencoded({extended: true}));
//application/json
app.use(bodyParser.json());

const mongoose = require('mongoose');
mongoose.connect('mongodb+srv://honeybeat1:test1234@boiler-plate.s3zgb.mongodb.net/test?retryWrites=true&w=majority', {
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
    return res.status(200).json({ success : true})
  })
})

app.listen(port, () => {
  console.log(`Example app listening at http://localhost:${port}`)
})
