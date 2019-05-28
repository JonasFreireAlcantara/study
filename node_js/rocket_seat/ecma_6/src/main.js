import api from './api';

class GitHub {
    constructor() {
        this.users = [];
        this.formElement = document.getElementById('repo-form');
        this.listElement = document.getElementById('repo-list');

        this.registerHandlers();
    }

    registerHandlers() {
        this.formElement.onsubmit = event => this.addRepository(event);
    }

    async addRepository(event) {
        event.preventDefault();

        let username = document.querySelector('input[name=repositorio]').value;
        if(username.length === 0)
            return;
        
        const response = await api.get(`/users/${username}`);

        const { name, bio, avatar_url } = response.data;

        this.users.push({
            name,
            bio,
            avatar_url,
        });

        this.render();
    }

    render() {
        this.listElement.innerHTML = '';

        this.users.forEach( user => {
            let imgEl = document.createElement('img');
            imgEl.setAttribute('src', user.avatar_url);

            let nameEl = document.createElement('strong');
            nameEl.appendChild(document.createTextNode(user.name));

            let bioEl = document.createElement('p');
            bioEl.appendChild(document.createTextNode(user.bio));

            let userEl = document.createElement('li');
            userEl.appendChild(imgEl);
            userEl.appendChild(nameEl);
            userEl.appendChild(bioEl);

            this.listElement.appendChild(userEl);
        });
    }
}


new GitHub();