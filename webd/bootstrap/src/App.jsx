import './App.css'
import Carousel from './Components/Carousel'
import Navbar from './Components/Navbar'

function App() {

  return (
    <>
      <div className="alert alert-success alert-dismissible">
        <button type="button" className="btn-close" data-bs-dismiss="alert"></button>
        <strong>Success!</strong> This alert box could indicate a successful or positive action.
      </div>
      <Navbar/>
      <Carousel/>
      <div class="progress">
        <div class="progress-bar bg-danger w-100 progress-bar-striped progress-bar-animated" >50%</div>
      </div>

      <div className="card w-25 bg-dark-subtle ">
        <img src="https://xinva.ai/wp-content/uploads/2023/12/106.jpg" className='card-img-top' alt="" />
        <div class="card-body text-center ">
          <h4 class="card-title">John Doe</h4>
          <p class="card-text">Some example text.</p>
          <a href="#" class="btn btn-primary">See Profile</a>
        </div>
      </div>
      
    </>
  )
}

export default App
