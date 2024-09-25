function List (){
    
    const fruits = [ 
        {id:1, name:"apple", calories: 95 },
        {id:2, name:"orange", calories: 45 },
        {id:3, name:"coconut", calories: 159},
        {id:4, name:"pineapple", calories: 37}
    ];
    // fruits.sort((a, b) => a.name.localeCompare(b.name);
    fruits.sort((a, b) => a.calories - b.calories) // sort numeric
    const list_items = fruits.map(fruit => <li key={fruit.id}> 
                                            {fruit.name} ({fruit.calories} calories)</li>);
    return (<ol>{list_items}</ol>);
}   
export default List