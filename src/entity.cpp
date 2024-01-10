#include "entity.h"
#include "shader.h"
#include "camera.h"
#include "texture_atlas.h"


Entity::Entity():texture_index(0) {

}

Entity::~Entity() {

}

void Entity::update() {
    m_shader->use();

    glm::mat4 view = Camera::get_instance()->get_view();
    m_shader->set_mat4("view", view);

    glm::mat4 model = glm::mat4(1.0);
    model = glm::translate(model, glm::vec3(0.0f));
    m_shader->set_mat4("model", model);

}

float Entity::get_x_offset() const {
    // if we have 10 texture in the texture atlas.
    // first texture is index 0 and laste texture
    // is index 9
    

    int num_rows = TextureAtlas::get_instance()->num_rows;
    int col = texture_index % num_rows;

    return (float) col / num_rows;
}


float Entity::get_y_offset() const {
    int num_rows = TextureAtlas::get_instance()->num_rows;
    int row = texture_index / num_rows;

    return (float) row / num_rows;

}
