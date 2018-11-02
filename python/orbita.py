#from vpython import *

# autor: Jonas Freire
# disciplina: Física aplicada a computação

# executar este programa em http://www.glowscript.org/
GlowScript 2.6 VPython


x_p = 0
y_p = 0
z_p = 0
x_l = 50
y_l = 0
z_l = 0

planeta = sphere(pos=vector(x_p,y_p,z_p), radius=2, color=color.red, make_trail=True)
lua = sphere(pos=vector(x_l,y_l,z_l), radius=2, color=color.blue, make_trail=True)

flecha_gravidade = arrow(pos=vector(x_l,y_l,z_l))
flecha_gravidade_x = arrow(pos=vector(x_l,y_l,z_l), color=color.green)
flecha_gravidade_y = arrow(pos=vector(x_l,y_l,z_l), color=color.yellow)


# velocidade inicial dos corpos
planeta.velocity = vector(0,0,0)
lua.velocity = vector(0,0,0)

massa_planeta = 1000 # kg
massa_lua = 1 # kg

# coeficiente gravitacional diferente do original por 10^11
coeficiente_gravitacional = 6.67408

distancia = vector(x_p-x_l, y_p-y_l, z_p-z_l).mag

# velocidade para lua entrar em orbita circular opcional
velocidade_orbita_circular = sqrt( (coeficiente_gravitacional*massa_planeta) /distancia )

# ajustar velocidade da lua na direção y
lua.velocity.y = velocidade_orbita_circular

#print("velocidade para lua manter orbita circular = ", velocidade_orbita_circular)


delta_t = 0.1
while True:
    rate(10)

    # atualizar distancia
    distancia = vector(x_p-x_l, y_p-y_l, z_p-z_l).mag

    # atualizar forca gravitacional
    fg = vector(x_p-x_l, y_p-y_l, z_p-z_l).norm() # computar primeiro direcao
    fg = fg * (coeficiente_gravitacional*massa_planeta*massa_lua)/distancia**2 # computar a sua magnitude

    # atualizar aceleracao gravitacional
    aceleracao_planeta = -fg/massa_planeta
    aceleracao_lua = fg/massa_lua

    # atualizar velocidade
    planeta.velocity = planeta.velocity + aceleracao_planeta*delta_t
    lua.velocity = lua.velocity + aceleracao_lua*delta_t

    # atualizar posicao
    planeta.pos = planeta.pos + planeta.velocity*delta_t
    lua.pos = lua.pos + lua.velocity*delta_t

    x_p = planeta.pos.x
    y_p = planeta.pos.y
    z_p = planeta.pos.z
    x_l = lua.pos.x
    y_l = lua.pos.y
    z_l = lua.pos.z

    # desenhar uma flecha da força gravitacional e seu componentes verticais e horizontais
    crescer_flecha = 1/fg.mag * 10
    flecha_gravidade.axis = fg*crescer_flecha
    flecha_gravidade.pos = vector(x_l, y_l, z_l)

    flecha_gravidade_y.axis = vector(0, (fg*crescer_flecha).y, 0)
    flecha_gravidade_y.pos = vector(x_l, y_l, z_l)

    flecha_gravidade_x.axis = vector((fg*crescer_flecha).x, 0, 0)
    flecha_gravidade_x.pos = vector(x_l, y_l, z_l)

    # print("forca gravitacional = ", fg.mag, " Newtons")
    # print("velocidade planeta = ", planeta.velocity.mag, " m/s")
    # print("velocidade lua = ", lua.velocity.mag, " m/s")
