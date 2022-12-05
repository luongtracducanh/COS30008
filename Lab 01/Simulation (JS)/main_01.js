
// A simple particle simulation

window.onload = function()
{
  var canvas = document.getElementById("canvas"),
      context = canvas.getContext("2d"),
      width = canvas.width = window.innerWidth,
      height = canvas.height = window.innerHeight,
      obj = new Particle2D( 0.0, 10.0, new Vector2D(10.0, 20.0), new Vector2D(4.0, 15.0), new Vector2D(0.0, -0.1))
      previous = 0;

//  obj.align(75);

  update(0);

  function update(timestamp)
  {
    context.clearRect(0, 0, width, height);

    obj.draw(context, width, height);

    if ( timestamp - previous > 30 )
    {
      previous = timestamp;

      obj.update();
    }

    if ( obj.position.y >= 20 )
    {
      requestAnimationFrame(update);
    }
  }
}
