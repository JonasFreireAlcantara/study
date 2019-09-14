const express = require('express');
const routes = express.Router();

const ProductController = require('./controllers/ProductController');
const PersonController = require('./controllers/PersonController');

routes.get('/product', ProductController.index);
routes.get('/product/:id', ProductController.show);
routes.post('/product', ProductController.store);
routes.put('/product/:id', ProductController.update);
routes.delete('/product/:id', ProductController.destroy);

routes.get('/person', PersonController.index);
routes.post('/person', PersonController.create);
routes.get('/person/:id', PersonController.show);

module.exports = routes;
