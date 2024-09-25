function Picture (){
    const imageUrl = './src/assets/fish.jpg';
    const handleClick = (e) => e.target.style.display = 'none';
    return (<img onClick={(e) => handleClick(e)} src={imageUrl}></img>);
}
export default Picture