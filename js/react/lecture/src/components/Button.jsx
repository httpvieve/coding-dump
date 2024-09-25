
function Button (){
    // let click_count = 0;
    // const handleClick = (event) => {
    //     if (click_count < 3) {
    //         click_count++;
    //         console.log(`${name} you clicked me ${click_count} time/s`);
    //     } else {
    //         console.log(`${name} stop clicking me`)
    //     }
    // }
    const handleClick = (e) => e.target.textContent = "OUCH!";
    return (<button onDoubleClick={(e) => handleClick(e)}>Click me!</button>);
}
export default Button