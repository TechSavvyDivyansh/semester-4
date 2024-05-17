import React from 'react'

export default function Carousel() {
  return (
    <div>
        <div id='demo' className="carousel slide" data-bs-ride="carousel">
            <div className="carousel-indicators">
                <button type="button" data-bs-target="#demo" data-bs-slide-to="0" className="active"></button>
                <button type="button" data-bs-target="#demo" data-bs-slide-to="1"></button>
                <button type="button" data-bs-target="#demo" data-bs-slide-to="2"></button>
            </div>

            <div className="carousel-inner">
                <div className="carousel-item active">
                <img src="https://images.musement.com/cover/0001/43/los-angeles_header-42380.jpeg" alt="Los Angeles" className="d-block" style={{width:'100vw',height:'70vh'}}/>
                </div>
                <div className="carousel-item">
                <img src="https://erepublic.brightspotcdn.com/dims4/default/002b172/2147483647/strip/false/crop/1000x563+0+51/resize/1200x675!/quality/90/?url=http%3A%2F%2Ferepublic-brightspot.s3.us-west-2.amazonaws.com%2Fb5%2F48%2F0fd02b1c4df7acadea1470bd37c8%2Fshutterstock-84639565.jpg" alt="Chicago" className="d-block" style={{width:'100vw',height:'70vh'}}/>
                </div>
                <div className="carousel-item">
                <img src="https://cdn.britannica.com/61/93061-050-99147DCE/Statue-of-Liberty-Island-New-York-Bay.jpg" alt="New York" className="d-block" style={{width:'100vw',height:'70vh'}}/>
                </div>
            </div>

            {/* <!-- Left and right controls/icons --> */}
            <button className="carousel-control-prev" type="button" data-bs-target="#demo" data-bs-slide="prev">
                <span className="carousel-control-prev-icon"></span>
            </button>
            <button className="carousel-control-next" type="button" data-bs-target="#demo" data-bs-slide="next">
                <span className="carousel-control-next-icon"></span>
            </button>
        </div>
        </div>
  )
}
