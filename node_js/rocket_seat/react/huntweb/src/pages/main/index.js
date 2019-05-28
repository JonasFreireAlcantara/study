import React, { Component } from 'react';
import { Link } from 'react-router-dom';

import './styles.css';

import api from '../../services/api';

export default class Main extends Component {
    state = {
        products: [],
        productInfo: {},
        actualPage: 1,
    }

    componentDidMount() {
        this.loadProducts();
    }

    loadProducts = async (pageNumber = 1) => {
        const response = await api.get(`/products?page=${pageNumber}`);

        const { docs, ...productInfo } = response.data;

        this.setState({ products: docs, productInfo, actualPage: pageNumber });
        console.log(response.data);
    }

    prevPage = () => {
        const { actualPage } = this.state; 
        
        if (actualPage === 1) return;

        const newPageNumber = actualPage - 1;
        this.loadProducts(newPageNumber);
    }

    nextPage = async () => {
        const { actualPage, productInfo } = this.state;

        if (actualPage === productInfo.pages) return;

        const newPageNumber = actualPage + 1;
        this.loadProducts(newPageNumber);
    }

    render() {
        return (
            <div className="product-list">
                {
                    this.state.products.map( product => (
                        <article key={product._id}>
                            <strong>{product.title}</strong>
                            <p>{product.description}</p>
                            <Link to={`/products/${product._id}`}>Acessar</Link>
                        </article>
                    ))
                }
                <div className="actions">
                    <button onClick={this.prevPage}>Anterior</button>
                    <button onClick={this.nextPage}>Próxima</button>
                </div>
            </div>
        );
    }
}
