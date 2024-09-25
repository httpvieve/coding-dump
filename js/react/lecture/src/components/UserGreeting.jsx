import PropTypes from 'prop-types'


function UserGreeting (props) {
    const welcomeMessage = <h2 className="welcome-msg">Welcome, {props.username}</h2> 
    const loginPropmt = <h2 className="login-prompt">Please log in to continue.</h2>
    return(props.isLoggedIn ? welcomeMessage: loginPropmt);
}

UserGreeting.PropTypes = {
    isLoggedIn: PropTypes.bool,
    username : PropTypes.string
}
UserGreeting.defaultProps = {
    isLoggedIn: false,
    username : "Guest"
}
export default UserGreeting