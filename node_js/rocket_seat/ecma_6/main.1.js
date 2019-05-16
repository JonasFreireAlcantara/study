class List {
    constructor() {
        this.data = [];
    }

    add(data) {
        this.data.push( data );
        console.log("Was add a new data = " + data);
    }
}


class TodoList extends List { }


const myTodoList = new TodoList();

document.getElementById("newTodoButtonItem").onclick = function() {
    myTodoList.add( document.getElementById("inputTodoItemName").value );
}
