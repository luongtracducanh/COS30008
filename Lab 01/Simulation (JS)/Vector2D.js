/*

  Simple functional 2D Vector class

*/

class Vector2D
{
  constructor(x, y)
  {
    this._x = x;
    this._y = y;
  }

  get x()
  {
    return this._x;
  }

  get y()
  {
    return this._y;
  }

  add(other)
  {
    return new Vector2D(this.x + other.x, this.y + other.y);
  }

  subtract(other)
  {
    return new Vector2D(this.x - other.x, this.y - other.y);
  }

  multiply(scalar)
  {
    return new Vector2D(this.x * scalar, this.y * scalar);
  }

  dot(other)
  {
    return this.x * other.x + this.y * other.y;
  }

  cross(other)
  {
    return this.x * other.y - this.y * other.x
  }

  length()
  {
    var val = Math.sqrt(this.x * this.x + this.y * this.y);

    return Math.round(val * 100) / 100.0;
  }

  normalize()
  {
    return this.divide( this.length() );
  }

  direction()
  {
    var val = Math.atan2( this.y, this.x ) * 180.0 / Math.PI;

    return Math.round(val * 100) / 100.0;
  }

  align(angle)
  {
      var radians = angle * Math.PI / 180.0,
          vector = new Vector2D(Math.cos(radians), Math.sin(radians));

      return vector.multiply( this.length() );
  }

  toString()
  {
    return "[" + Math.round(this.x) + "," + Math.round(this.y) + "]"
  }

  draw(context, origin)
  {
    var end_x = origin.x + this.x * 10, // to amplify effect
        end_y = origin.y - this.y * 10;

    context.beginPath();
    context.strokeStyle = "blue";
    context.setLineDash([]);
    context.lineWidth = 3;
    context.moveTo(origin.x, origin.y);
    context.lineTo(end_x, end_y);
    context.stroke();
  }
}
