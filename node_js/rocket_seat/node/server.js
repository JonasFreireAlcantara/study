const express = require('express');
const mongoose = require('mongoose');
const cors = require('cors');

// Initializing app
const app = express();
app.use(express.json());
app.use(cors());

// MongoDB connection with mongoose
mongoose.connect('mongodb://localhost:27017/nodeapi', {
  useNewUrlParser: true
});
require('./src/models/Product');
require('./src/models/Person');

// Routes
app.use('/api', require('./src/routes'));

// Startup app to listen at port 3001
app.listen(3001);
