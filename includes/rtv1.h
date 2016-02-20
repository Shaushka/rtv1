#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../libft/includes/libft.h"

# define SCREEN_W			1280
# define SCREEN_H			960

# define INTER_W			SCREEN_W / 5
# define INTER_H			SCREEN_H / 5

# define AMBIANT			0.4
# define MAX_VISION(h)		(3570 + sqrt((h)))
# define PI					3.14159265
# define RATIO				(PI / 180)
# define BUF_SIZE			10
# define MAX_DEPTH			5

# define XPM_DEFAULT		"texture/default_texture.xpm"
# define D_XP_PATH			"./../"

extern int		g_depth;

typedef	struct		s_vector
{
	float			x;
	float			y;
	float			z;
}					t_vector;

typedef	struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef	enum {
	SPHERE,
	PLANE,
	CYLINDER,
	CONE
}	t_type;

typedef	enum {
	NORMAL
}	t_lighttype;

typedef	enum {
	NONE,
	OBJECT,
	LIGHT,
	TEXTURE
}	t_fam;

typedef	struct		s_object
{
	struct s_object	*next;
	t_type			type;
	t_color			color;
	t_vector		pos;
	t_vector		dir;//cylinder cone
	t_vector		normal;//plan
	t_vector		cut;
	int				checkered;//dallage_carreaux
	float			radius;//sphere cone cylindre
	float			height;//cone cylindre
	float			shine;//brillance
	float			reflect;//reflexion
	float			refraction;
	int				bundle;
}					t_object;

typedef struct		s_light
{
	t_lighttype		type;
	t_vector		pos;
	t_vector		dir;
	t_color			color;
	float			intensity;
	float			ambiant;
	struct s_light	*next;
}					t_light;

typedef struct		s_scene
{
	void			*l_obj;
	t_light			*light;
}					t_scene;

typedef struct		s_cam
{
	t_vector		pos;
	t_vector		dir;
	t_vector		h;
	t_vector		d;
}					t_cam;

typedef struct		s_img
{
	void			*img_ptr;
	char			*img_data;
	int				bpp;
	int				opp;
	int				sizeline;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct		s_mlx_init
{
	t_img			img;
	void			*mlx;
	void			*win;
}					t_mlx_init;

typedef struct		s_keyring
{
	double			mouse_x;
	double			mouse_y;
	int				selected_light;
	int				selected_obj;
	int				mode;
	t_cam			cam_inc;
	t_mlx_init		interface;
}					t_keyring;

typedef struct		s_env
{
	t_mlx_init		mlx_init;
	t_scene			*scene;
	t_light			*lights;
	t_cam			cam;
	t_keyring		key;
	float			ambiant;
}					t_env;

typedef struct		s_node
{
	t_fam			family;
	char			*value;
	char			*type;
	struct s_node	*next;
}					t_node;

typedef struct		s_parse
{
	char			*name;
	t_node			*nodes;
	t_object		*obj;
	t_light			*light;
}					t_parse;

/*
**	main.c
*/
void				ft_initialize(t_env *e);

/*
**	initialization.c
*/
void				init_keyring(t_env *e);
void				ft_exit(char *str, int n);
void				quit_and_free(t_env *e);
void				init_env(t_env *e, char *av);
int					expose_hook(t_env *e);
void				init_and_draw(t_env *e, char *av);
void				init_obj(t_object *node);
void				init_scene(t_env *e);
void				new_img_in_old_env(t_env *e, t_env *old);

/*
**	premade_objects.c
*/
void				set_list_obj(t_env *e);

/*
**	render.c
*/
void				ft_render(t_env *e);

/*
**	intersection.c
*/
float				intersection(t_object *tmp, t_vector ray, t_vector pos);

/*
**	hook_functions.c
*/
int					expose_hook(t_env *e);
void				ft_new_obj_hook(int keycode, t_env *e);
int					key_press_hook(int keycode, t_env *e);

/*
**	graphics_tools.c
*/
void				put_pixel_to_img(t_env *e, int addr, t_color color);
void				set_color_from_img(t_color *color, char *data, int addr);
void				set_color_from_rgb(t_color *color, int r, int g, int b);
void				get_true_color_value(t_color *color);
void				blend_color(t_color *c, t_color c1, t_color c2,
								double percent);

/*
**	----------> USER INPUT SYSTEM <-----
*/
/*
**	create_scene.c
*/
void				create_scene(t_env *e);

/*
**	add_shape.c
*/
void				input_sphere(t_env *e);
void				input_plane(t_env *e);
void				input_cylinder(t_env *e);
void				input_cone(t_env *e);

/*
**	assign_color.c
*/
void				color(t_color *color);
void				color_choice(t_color *color);

/*
**	create_object.c
*/

t_object			*create_object(t_env *e);
t_light				*create_light(t_env *e);

t_object			*create_object_p();
t_light				*create_light_p();

/*
**	infos_shapes.c
*/
void				radius(t_object *node);
void				height(t_object *node);
void				constant(t_object *node);
/*
** int			count_objects(t_env *e);
*/
/*
**	input_normal.c
*/
void				assign_normal(t_object *node, char *str);//static ?
void				normal(t_object *node);

/*
**	input_vectors_clean.c
*/
char				**remove_spaces(char *str, int i, char **clean);//static ?
void				separators(char *str);//static ?
char				*no_more_spaces(char *str);

/*
**	input_verification.c
*/
int					is_slashes_and_digits(char *str);//static ?
int					is_vector(char *str);//static ?
int					correct_input(char *str);
void				remove_bn(char **str);
/*
**	input_position.c
*/
char				*cut_pos(char *str, int i);
int					check_values(char *str, int min, int max);
void				assign_pos(t_object *node, char *str);
void				position(t_object *node);

/*
**	----------> GEOMETRY <-----
*/
/*
**	trigo.c
*/
float				d_cos(float angle);
float				d_sin(float angle);
float				d_acos(float value);

/*
**>----------> INTERSECTION <-----
*/

/*
**	sphere.c
*/
t_object			set_sphere(t_vector pos, float radius);
float				inter_sphere(t_vector cam_pos, t_vector ray,
								t_object sphere);
t_vector			normal_sphere(t_vector cam, t_object obj, t_vector ray);

/*
**	plane.c
*/
t_object			set_plane(t_vector pos, t_vector normal);
float				inter_plane(t_vector cam_pos, t_vector ray, t_object plane);
t_vector			normal_plane(t_object obj, t_vector ray);

/*
**	cylinder.c
*/
t_object			set_cylinder(t_vector pos, t_vector dir, float r, float h);
float				inter_cylinder(t_vector cam_pos, t_vector ray,
									t_object obj);
t_vector			normal_cylinder(t_vector cam, t_object obj, t_vector ray);

/*
**	cone.c
*/
t_object			set_cone(t_vector pos, t_vector dir, float r, float h);
float				inter_cone(t_vector cam_pos, t_vector ray, t_object obj);
t_vector			normal_cone(t_vector cam, t_object obj, t_vector ray);

/*
**	item_cut.c
*/
int					item_cut(t_vector cam, t_vector ray, t_object item);

/*
**>----------> LIGHTS <-----
*/

/*
**	light.c
*/

t_vector			calc_normal(t_vector pos, t_object obj, t_vector inter);
t_color				ft_light (t_light *ls, t_object o, t_vector inter,
								t_env *e);
void				init_lights(t_env *e);
t_color				shall_i_refract(t_object item, t_vector inter, t_env *e);
t_color				shall_i_reflect(t_object item, t_vector inter, t_env *e);

/*
**	light_diffuse.c
*/
float				diffuse_light(t_light l, t_object o, t_vector inter,
									t_env *e);

/*
**	light_specular.c
*/
float				specular_light(t_light l, t_object o, t_vector inter,
									t_env *e);

/*
**	reflection.c
*/
t_color				reflection(t_object item, t_vector inter, t_env *e);

/*
**	refraction.c
*/
t_color				refraction(t_object item, t_vector inter, t_env *e);

/*
**	ray_tracing.c
*/
t_color				check_collision(t_env *e, t_vector ray, t_vector pos);

/*
**	vector.c
*/
t_vector			set_vector(t_vector v, float x, float y, float z);
float				dotpro_vector(t_vector a, t_vector b);
float				norm_vector(t_vector v);
t_vector			unit_vector(t_vector v);
float				sq_vector(t_vector a);

/*
**	vector2.c
*/
t_vector			add_vector(t_vector v, t_vector u);
t_vector			sub_vector(t_vector v, t_vector u);
t_vector			cross_vector(t_vector v, t_vector u);
t_vector			mult_vector(t_vector a, float m);

/*
**>----------> COLOR AND TEXTURE <-----
*/

/*
**	texture.c
*/
t_color				checkered_floor(t_vector coord);

/*
**	color.c
*/
t_color				add_color(t_color a, t_color b);
t_color				mult_color(t_color color, float coef);
t_color				check_color(t_color color);

/*
**>----------> PARSER <-----
*/

/*
**	parser
*/
int					check_shit(char *str);
int					get_the_mark(char *str);
void				open_file(char *file, t_parse *parse, t_env *e);
float				ft_atof(char *number);
void				assign_color(t_color *color, char *str);
void				assign_color_p(t_object **obj, char *str);
void				assign_lightcolor_p(t_light **obj, char *str);
void				assign_pos_p(t_object **obj, char *str);
void				assign_cut_p(t_object **obj, char *str);
void				assign_dir_p(t_object **obj, char *str);
void				assign_normal_p(t_object **obj, char *str);
void				assign_normal(t_object *node, char *str);
void				assign_pos(t_object *node, char *str);
void				assign_pos_light(t_light *node, char *str, int n);
int					check_values(char *str, int min, int max);
char				*cut_pos(char *str, int i);
void				separators(char *str);
char				*no_more_spaces(char *str);
char				**remove_spaces(char *str, int i, char **clean);
int					correct_input(char *str);
int					is_vector(char *str);
int					is_slashes_and_digits(char *str);
void				init_obj(t_object *node);
void				init_light(t_light *node);
t_vector			set_vector(t_vector v, float x, float y, float z);
void				print_nodes(t_node *nodes);
void				print_result(t_parse *parse);
char				*recup_name(t_node *node, char *get, char c);
int					get_size(char *get, int i, char c);
void				set_light_type(char *name, t_light *obj);
void				set_light_param(char *value, char *data, t_light *obj);
void				set_object_type(char *name, t_object *obj);
void				set_object_param(char *value, char *data, t_object *obj);
void				error_in_parse(char *str);
void				get_instr(char *get, t_parse *parse, t_env *e);

int					set_node(t_node **nodes, int pos, char **tab);
void				recup_nodes(t_node *nodes, t_parse *parse, t_env *e);
/*
**>----------> INTERFACE <----------
*/

/*
**	ft_loading_bar.c
*/
void				ft_gen_loading_border(t_env *e);
void				ft_fill_loading_border(t_env *e, int x);
int					ft_loading_bar(int x, t_env *e);

/*
**	ft_print_2d_shapes.c
*/
void				ft_print_line(t_env *ev, t_color c, t_vector s, t_vector e);
void				ft_print_square(t_color c, t_vector st, t_vector en,
									t_env *e);

/*
**	ft_keyring_cam_interface.c
*/
int					ft_get_cm_cmd_interface_2(int x, int y, t_env *e);
int					ft_get_cm_cmd_interface(int x, int y, t_env *e);
void				ft_mod_cam_inc(t_env *e, int mod);
void				spawn_cam_pos_controls(t_color c, t_vector v, t_env *e);
void				spawn_cam_dir_controls(t_color c, t_vector v, t_env *e);

/*
**	ft_keyring_cam_interface_2.c
*/
void				spawn_cam_menu(t_env *e);
char				*ft_print_pending_campos_modif2(t_env *e);
void				ft_print_pending_campos_modif(t_env *e);
char				*ft_print_pending_camdir_modif2(t_env *e);
void				ft_print_pending_camdir_modif(t_env *e);

/*
**	ft_keyring_main_menu.c
*/
void				spaw_main_menu(t_env *e);

/*
**	ft_keyring.c
*/
int					ft_get_mm_cmd_interface(int x, int y, t_env *e);
int					ft_get_cmd_interface(int press, int x, int y, t_env *e);
int					ft_exec_cmd(int mod, t_env *e);
int					ft_click(int press, int x, int y, t_env *e);
void				ft_print_pending_light(t_env *e, int mod);
void				ft_print_pending_obj(t_env *e, int mod);

/*
**	ft_keyring_reset.c
*/
void				set_cam_to_zero(t_cam *cam);
void				init_keyring(t_env *e);
void				new_interface_image(t_env *e);
void				hide_interface_image(t_env *e);

/*
**	ft_keyring_apply.c
*/
void				ft_keyring_cammod_reset_pos(t_env *e, int render);
void				ft_keyring_cammod_reset_dir(t_env *e, int render);
void				ft_keyring_cammod_apply(t_env *e);
void				ft_keyring_lightmod_apply(t_env *e);
void				ft_keyring_objmod_apply(t_env *e);

/*
**	ft_keyring_light_interface.c
*/
void				spawn_light_menu(t_env *e);
void				spawn_light_pos_controls(t_color c, t_vector v, t_env *e);
void				spawn_light_dir_controls(t_color c, t_vector v, t_env *e);
void				spawn_light_int_controls(t_color c, t_vector v, t_env *e);
void				spawn_light_col_controls(t_color c, t_vector v, t_env *e);

/*
**	ft_keyring_light_interface_cmd.c
*/
int					ft_get_lm_cmd_interface_4(int x, int y, t_env *e);
int					ft_get_lm_cmd_interface_3(int x, int y, t_env *e);
int					ft_get_lm_cmd_interface_2(int x, int y, t_env *e);
int					ft_get_lm_cmd_interface(int x, int y, t_env *e);
void				ft_mod_light_inc(t_env *e, int mod);

/*
**	ft_keyring_utility.c
*/
t_light				*ft_get_light_at_nb(int nb, t_light *s);
void				ft_get_next_light(t_env	*e);
void				ft_get_next_obj(t_env *e);
t_object			*ft_get_obj_at_nb(int nb, t_object *s);

/*
**	ft_keyring_light_interface_2.c
*/
void				ft_print_pending_lightpos_modif(t_light *l, t_env *e);
void				ft_print_pending_lightdir_modif(t_light *l, t_env *e);
void				ft_print_pending_lightcol_modif(t_light *l, t_env *e);
void				ft_print_pending_lightint_modif(t_light *l, t_env *e);
void				ft_print_selected_light(t_env *e);

/*
**	ft_keyring_object_interface.c
*/
int					ft_get_om_cmd_interface(int x, int y, t_env *e);
void				spawn_obj_menu(t_env *e);
void				spawn_obj_pos_controls(t_color c, t_vector v, t_env *e);
void				ft_print_pending_objpos_modif(t_object *l, t_env *e);
void				ft_print_selected_obj(t_env *e);
void				ft_mod_obj_inc(t_env *e, int mod);
void				ft_mod_grouped_obj(t_env *e, int mod, int index);
int					ft_get_new_bundle_nb(t_env *e);

/*
**	ft_keyring_ui.c
*/
void				ft_print_obj_ui(t_env *e);
void				ft_print_light_ui(t_env *e);
void				ft_print_cam_ui(t_env *e);
void				ft_print_mm_ui(t_env *e);

/*
**	cadeau Merlin : FORK
*/

void				get_scene(t_env *e, char *file);
void				ft_wait_exit(int n);

/*
**	ft_texture_load.c
*/
t_img				ft_get_texture(char *xpm_file_name, int xpm_w, int xpm_h,
									t_env *e);

/*
**	ft_free_utility_2.c
*/
char				**ft_free_char_tab(char **del);
int					**ft_free_int_tab(int **del, int len);
void				ft_free_obj_lst(t_object *start);
void				ft_free_light_lst(t_light *start);

/*
**	ft_free_utility.c
*/
void				ft_free_node_lst(t_node *start);
void				ft_free_parse(t_parse *del);
void				ft_free_one_node(t_node *one_del);

/*
**	ft_keyring_nape_generator.c
*/
void				ft_nape_generator_init(t_env *e);
void				ft_quater_nappe(t_vector t, t_env *e, t_vector s,
									int link_nb);

#endif
