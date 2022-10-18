/*

  Simple 2D Particle class

*/

class Particle2D
{
  constructor(mass, r, position, velocity, acceleration)
  {
    this._mass = mass;
    this._radius = r;
    this._position = position;
    this._velocity = velocity;
    this._acceleration = acceleration;
  }

  get mass()
  {
    return this._mass;
  }

  get radius()
  {
    return this._radius;
  }

  get position()
  {
    return this._position;
  }

  get velocity()
  {
    return this._velocity;
  }

  get acceleration()
  {
    return this._acceleration;
  }

  applyAcceleration(acceleration)
  {
    this._acceleration = this._acceleration.add(acceleration)
  }

  direction()
  {
    return this._velocity.direction();
  }

  align(angle)
  {
    this._velocity = this._velocity.align(angle)
  }

  speed()
  {
    return this._velocity.length();
  }

  update()
  {
      this._velocity = this.velocity.add(this.acceleration);
      this._position = this.position.add(this.velocity);
  }

  draw(context, rel_x, rel_y)
  {
    var x_pos = this.position.x,
        y_pos = rel_y - this.position.y;

    context.fillStyle = "rgba(0, 0, 0, 255)";
    context.beginPath();
    context.arc(x_pos, y_pos, this.radius, 0, Math.PI * 2, false);
    context.fill();

    context.font = "14px Verdana";
    context.fillText("Speed: " + this.speed().toString(), x_pos, y_pos - 50)
    context.fillText("Direction: " + this.direction().toString(), x_pos, y_pos - 30)
    context.fillText("Position: " + this.position.toString(), x_pos, y_pos - 10)
    this.velocity.draw(context, new Vector2D(x_pos, y_pos))
  }
}
