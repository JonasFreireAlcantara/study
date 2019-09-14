const mongoose = require('mongoose');

const PersonSchema = mongoose.Schema({
    name: {
        type: String,
        required: true
    },
    age: {
        type: Number,
        required: true
    },
    nickname: {
        type: String
    }
});

mongoose.model('Person', PersonSchema);