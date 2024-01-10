#ifndef ENTITY_H
#define ENTITY_H

struct Shader;


struct Entity {
    Entity();
    virtual ~Entity();

    virtual void render() = 0;
    virtual void update();

    Shader* m_shader;

    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;

    int texture_index;

    float get_x_offset() const;
    float get_y_offset() const;
    void update_texture();


};
#endif

