import turtle

def draw_shapes():
  carbet = turtle.getscreen()
  carbet.bgcolor("purple")

  #square
  sq_pen = turtle.Turtle()
  sq_pen.shape("turtle")
  sq_pen.color("pink")
  sq_pen.speed(4)
  i = 0
  while i < 4:
    sq_pen.forward(100)
    sq_pen.right(90)
    i += 1


  #circle
  cir_pen = turtle.Turtle()
  cir_pen.shape("circle")
  cir_pen.color("blue")
  cir_pen.speed(5)
  cir_pen.circle(100)

  #triangle
  tri_pen = turtle.Turtle()
  tri_pen.shape("classic")
  tri_pen.color("red")
  tri_pen.speed(5)
  i = 0
  while i < 3:
    tri_pen.forward(100)
    tri_pen.right(45)
    i += 1

  carbet.exitonclick()
  
draw_shapes()