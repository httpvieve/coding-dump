import PropTypes from 'prop-types'
function Student (props){

    return (
        <div className="student">
            <p>Name: {props.name}</p>
            <p>Age: {props.age}</p>
            <p>Student: {props.is_student ? "Yes" : "No"}</p>
        </div>
    );
}
Student.propTypes = {
    name: PropTypes.string,
    age: PropTypes.number,
    is_student: PropTypes.bool
}

Student.defaultProps = {
    name: "Guest",
    age: 0,
    is_student: false
}
export default Student