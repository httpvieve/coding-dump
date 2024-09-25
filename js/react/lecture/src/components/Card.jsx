import profilePicture from '../assets/fish.jpg'

function Card (){
    return (
        <div className="card">
            <img className="card-image" src={profilePicture} alt="profile picture"></img>
            <h2 className='card-title'>Vieve</h2>
            <p className='card-text'>I like maths and stupid looking animals</p>
        </div>
    );
}
export default Card
