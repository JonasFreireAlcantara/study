const mongoose = require('mongoose');

const Person = mongoose.model('Person');

module.exports = {
    async index(req, res) {
        const products = await Person.find();

        return res.json(products);
    },

    async create(req, res) {
        const product = await Person.create(req.body);

        return res.json(product);
    },

    async show(req, res) {
        const product = await Person.findById(req.params.id);

        return res.json(product);
    }
};