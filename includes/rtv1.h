/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 18:17:28 by mguillon          #+#    #+#             */
/*   Updated: 2016/02/21 19:48:37 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define XPM_DEFAULT		"./texture/default.xmp"

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

/*
**	type -> all
**	color -> all
**	pos -> all
**	dir -> cylinder cone
**	normal -> plan
**	cut -> all
**	checkered -> dallage_carreaux
**	radius -> sphere cone cylindre
**	height -> cone cylindre
**	shine -> brillance
**	reflect -> reflexion
**	refraction -> all
**	bundle -> all
*/

typedef	struct		s_object
{
	struct s_object	*next;
	t_type			type;
	t_color			color;
	t_vector		pos;
	t_vector		dir;
	t_vector		normal;
	t_vector		cut;
	int				checkered;
	float			radius;
	float			height;
	float			shine;
	float			reflect;
	float			refraction;
	int				bundle;
}					t_object;

typedef struct		s_light
{
	int				bundle;
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
**	assign_pos_light.c
*/
void				assign_pos_light(t_light *node, char *str, int n);

/*
**	color.c
*/
t_color				mult_color(t_color color, float coef);
t_color				add_color(t_color a, t_color b);
t_color				check_color(t_color color);

/*
**	cone.c
*/
t_object			set_cone(t_vector pos, t_vector dir,
							float radius, float height);
float				inter_cone(t_vector cam_pos, t_vector ray, t_object cone);
t_vector			normal_cone(t_vector cam, t_object cone, t_vector ray);

/*
**	cylinder.c
*/
t_object			set_cylinder(t_vector pos, t_vector dir, float radius,
									float h);
float				inter_cylinder(t_vector pos, t_vector ray,
									t_object cylinder);
t_vector			normal_cylinder(t_vector cam, t_object cylinder,
									t_vector ray);

/*
**	debug.c
*/
void				error_in_parse(char *str);
void				print_vector(t_vector vec, char *pre);
void				print_color(t_color col, char *pre);

/*
**	exit_and_quit.c
*/
void				ft_exit(char *str, int n);
void				quit_and_free(t_env *e);

/*
**	file_and_scene.c
*/
void				open_file(char *file, t_parse *parse, t_env *e);
void				get_scene(t_env *e, char *file);

/*
**	ft_free_utility_2.c
*/
void				ft_free_one_node(t_node *one_del);
void				ft_free_node_lst(t_node *start);
void				ft_free_parse(t_parse *del);

/*
**	ft_free_utility.c
*/
char				**ft_free_char_tab(char **del);
int					**ft_free_int_tab(int **del, int len);
void				ft_free_obj_lst(t_object *start);
void				ft_free_light_lst(t_light *start);

/*
**	ft_texture_load.c
*/
t_img				ft_get_texture(char *xpm_file_name, int xpm_w, int xpm_h,
									t_env *e);

/*
**	get_instruction.c
*/
void				get_instr(char *get, t_parse *parse, t_env *e);

/*
**	graphic_tools.c
*/
void				put_pixel_to_img(t_env *e, int addr, t_color color);
void				blend_color(t_color *c, t_color c1, t_color c2,
								double percent);
void				set_color_from_rgb(t_color *color, int r, int g, int b);
void				set_color_from_img(t_color *color, char *data, int addr);
void				get_true_color_value(t_color *color);

/*
**	hook_function_2.c
*/
int					key_press_hook_3(int keycode, t_env *e);
int					key_press_hook_2(int keycode, t_env *e);
int					key_press_hook(int keycode, t_env *e);

/*
**	hook_function.c
*/
int					expose_hook(t_env *e);
void				ft_new_obj_hook(int keycode, t_env *e);
void				ft_generatore(int x, int y, int z, t_env *e);
int					spawn_soft_light(t_env *e);
t_light				*ft_new_light_hook(t_vector pos, int link_nb);
void				ft_spawn_christmas(t_env *e);

/*
**	initialization.c
*/
void				new_img_in_old_env(t_env *e, t_env *old);
void				init_and_draw(t_env *e, char *av);
void				init_obj(t_object *node);
void				init_light(t_light *node);
void				init_scene(t_env *e);

/*
**	intersection.c
*/
float				intersection(t_object *tmp, t_vector ray, t_vector pos);

/*
**	item_cut.c
*/
int					item_cut(t_vector pos, t_vector ray, t_object item);

/*
**	light_ambiant.c
*/
t_color				ambiant_light(t_object item);

/*
**	light_diffuse.c
*/
float				diffuse_light(t_light light, t_object item, t_vector inter,
									t_env *e);

/*
**	light_reflection.c
*/
t_vector			ray_reflect(t_vector normal, t_vector inter);
t_color				reflection(t_object item, t_vector inter, t_env *e);

/*
**	light_specular.c
*/
float				specular_light(t_light light, t_object item,
									t_vector inter, t_env *e);

/*
**	light.c
*/
int					check_shadow(t_light light, t_vector inter_ray, t_env *e);
t_vector			calc_normal(t_vector pos, t_object item,
								t_vector inter_ray);
t_color				ft_light(t_light *lights, t_object item, t_vector inter,
								t_env *e);
void				init_lights(t_env *e);

/*
**	loading_bar.c
*/
void				ft_gen_loading_border(t_env *e);
void				ft_fill_loading_border(t_env *e, int x);
int					ft_loading_bar(int x, t_env *e);

/*
**	main_fork.c
*/
void				ft_wait_exit(int n);
int					main(int argc, char **argv);

/*
**	matrix.c
*/
t_vector			vect_rot_angle(t_vector u, float o);

/*
**	options_parser_2.c
*/
void				assign_normal_p(t_object **obj, char *str);
void				assign_dir_p(t_object **obj, char *str);
void				assign_pos_p(t_object **obj, char *str);

/*
**	options_parser.c
*/
void				assign_cut_p(t_object **obj, char *str);
void				assign_color_p(t_object **obj, char *str);
void				assign_lightcolor_p(t_light **obj, char *str);

/*
**	parse_checks.c
*/
int					check_shit(char *str);
int					get_the_mark(char *str);

/*
**	parser.c
*/
char				*ft_del_and_trim(char **swp, char **tab, int pos);
int					set_node(t_node **nodes, int pos, char **tab);

/*
**	plane.c
*/
t_object			set_plane(t_vector pos, t_vector normal);
int					defined_plane(t_vector cam_pos, t_vector ray, t_object obj);
float				inter_plane(t_vector cam_pos, t_vector ray, t_object obj);
t_vector			normal_plane(t_object obj, t_vector ray);

/*
**	premade_objects.c
*/
void				set_list_obj(t_env *e);

/*
**	parser.c
*/
char				*ft_del_and_trim(char **swp, char **tab, int pos);
int					set_node(t_node **nodes, int pos, char **tab);

/*
** ray_tracing.c
*/
t_color				check_collision(t_env *e, t_vector ray, t_vector pos);

/*
**	recup_node.c
*/
void				recup_nodes(t_node *nodes, t_parse *parse, t_env *e);

/*
**	refraction.c
*/
float				ft_cost(float eta, float cosi);
float				inside(t_object item, t_vector inter, t_vector *norm);
t_vector			ft_refray(t_vector inter, t_vector norm, float eta,
								float cosi);
t_color				refraction(t_object item, t_vector inter, t_env *e);

/*
**	render.c
*/
void				ft_render(t_env *e);

/*
**	setter.c
*/
void				set_object_type(char *name, t_object *obj);
void				set_object_param(char *value, char *data, t_object *obj);
void				set_light_type(char *name, t_light *obj);
void				set_light_param(char *value, char *data, t_light *obj);

/*
**	shall_i_reflect_and_refract.c
*/
t_color				shall_i_reflect(t_object item, t_vector inter, t_env *e);
t_color				shall_i_refract(t_object item, t_vector inter, t_env *e);

/*
**	sphere.c
*/
t_object			set_sphere(t_vector pos, float radius);
float				inter_sphere(t_vector cam_pos, t_vector ray, t_object obj);
t_vector			normal_sphere(t_vector cam, t_object obj, t_vector ray);

/*
**	texture.c
*/
t_color				checkered_floor(t_vector coord);

/*
**	trigo.c
*/
float				d_cos(float angle);
float				d_sin(float angle);
float				d_acos(float value);

/*
**	vector.c
*/
t_vector			set_vector(t_vector v, float x, float y, float z);
float				dotpro_vector(t_vector a, t_vector b);
float				norm_vector(t_vector a);
t_vector			unit_vector(t_vector v);
float				sq_vector(t_vector a);

/*
**	vector2.c
*/
t_vector			add_vector(t_vector a, t_vector b);
t_vector			sub_vector(t_vector a, t_vector b);
t_vector			cross_vector(t_vector a, t_vector b);
t_vector			mult_vector(t_vector a, float m);

/*
**	interactive/add_shape.c
*/
void				input_plane(t_env *e);
void				input_sphere(t_env *e);
void				input_cylinder(t_env *e);
void				input_cone(t_env *e);

/*
**	interactive/assign_color.c
*/
void				assign_color(t_color *color, char *str);
void				color(t_color *color);
void				color_choice(t_color *color);

/*
**	interactive/create_object.c
*/
t_object			*create_object_p(void);
t_light				*create_light_p(void);
t_object			*create_object(t_env *e);
t_light				*create_light(t_env *e);

/*
**	interactive/create_scene.c
*/
void				create_scene(t_env *e);

/*
**	interactive/infos_shapes.c
*/
void				radius(t_object *node);
void				height(t_object *node);
void				shine(t_object *node);

/*
**	interactive/input_normal.c
*/
void				assign_normal(t_object *node, char *str);
void				normal(t_object *node);

/*
**	interactive/input_position.c
*/
char				*cut_pos(char *str, int i);
char				*cleanit(char *str);
int					check_values(char *str, int min, int max);
void				assign_pos(t_object *node, char *str);
void				position(t_object *node);

/*
**	interactive/input_vectors_clean.c
*/
char				**remove_spaces(char *str, int i, char **clean);
char				*no_more_spaces(char *str);
void				separators(char *str);

/*
**	interactive/input_verification.c
*/
int					is_slashes_and_digits(char *str);
int					is_vector(char *str);
void				remove_bn(char **str);
int					correct_input(char *str);

/*
**	keyring/ft_keyring_apply.c
*/
void				ft_keyring_cammod_reset_pos(t_env *e, int render);
void				ft_keyring_cammod_reset_dir(t_env *e, int render);
void				ft_keyring_lightmod_apply(t_env *e);
void				ft_keyring_objmod_apply(t_env *e);
void				ft_keyring_cammod_apply(t_env *e);

/*
**	keyring/ft_keyring_cam_interface_2.c
*/
void				spawn_cam_menu(t_env *e);
char				*ft_print_pending_campos_modif2(t_env *e);
void				ft_print_pending_campos_modif(t_env *e);
char				*ft_print_pending_camdir_modif2(t_env *e);
void				ft_print_pending_camdir_modif(t_env *e);

/*
**	keyring/ft_keyring_cam_interface.c
*/
int					ft_get_cm_cmd_interface_2(int x, int y, t_env *e);
int					ft_get_cm_cmd_interface(int x, int y, t_env *e);
void				ft_mod_cam_inc(t_env *e, int mod);
void				spawn_cam_pos_controls(t_color c, t_vector v, t_env *e);
void				spawn_cam_dir_controls(t_color c, t_vector v, t_env *e);

/*
**	keyring/ft_keyring_light_interface_3.c
*/
void				ft_mod_grouped_light(t_env *e, int mod, int index);
int					ft_get_new_bundle_nb_l(t_env *e);
void				ft_set_one_light(t_light *swp, int mod);

/*
**	keyring/ft_keyring_light_interface_2.c
*/
void				ft_print_pending_lightpos_modif(t_light *l, t_env *e);
void				ft_print_pending_lightdir_modif(t_light *l, t_env *e);
void				ft_print_pending_lightcol_modif(t_light *l, t_env *e);
void				ft_print_pending_lightint_modif(t_light *l, t_env *e);
void				ft_print_selected_light(t_env *e);

/*
**	keyring/ft_keyring_light_interface_cmd.c
*/
int					ft_get_lm_cmd_interface_4(int x, int y, t_env *e);
int					ft_get_lm_cmd_interface_3(int x, int y, t_env *e);
int					ft_get_lm_cmd_interface_2(int x, int y, t_env *e);
int					ft_get_lm_cmd_interface(int x, int y, t_env *e);
void				ft_mod_light_inc(t_env *e, int mod);

/*
**	keyring/ft_keyring_light_interface.c
*/
void				spawn_light_menu(t_env *e);
void				spawn_light_pos_controls(t_color c, t_vector v, t_env *e);
void				spawn_light_dir_controls(t_color c, t_vector v, t_env *e);
void				spawn_light_col_controls(t_color c, t_vector v, t_env *e);
void				spawn_light_int_controls(t_color c, t_vector v, t_env *e);

/*
**	keyring/ft_keyring_main_menu.c
*/
int					ft_get_mm_cmd_interface(int x, int y, t_env *e);
void				spaw_main_menu(t_env *e);

/*
**	kyring/ft_keyring_nape_generator.c
*/
void				ft_nape_generator_init(t_env *e);
void				ft_jellybeans_generator(t_env *e);
void				ft_quater_nappe(t_vector t, t_env *e, t_vector s,
									int link_nb);

/*
**	keyring/ft_keyring_object_interface_2.c
*/
int					ft_get_om_cmd_interface(int x, int y, t_env *e);
void				ft_mod_grouped_obj(t_env *e, int mod, int index);
int					ft_get_new_bundle_nb(t_env *e);

/*
**	keyring/ft_keyring_object_interface.c
*/
void				spawn_obj_menu(t_env *e);
void				spawn_obj_pos_controls(t_color c, t_vector v, t_env *e);
void				ft_print_pending_objpos_modif(t_object *l, t_env *e);
void				ft_print_selected_obj(t_env *e);
void				ft_mod_obj_inc(t_env *e, int mod);

/*
**	keyring/ft_keyring_reset.c
*/
void				set_cam_to_zero(t_cam *cam);
void				init_keyring(t_env *e);
void				new_interface_image(t_env *e);
void				hide_interface_image(t_env *e);

/*
**	keyring/ft_keyring_shape.c
*/
void				ft_print_line(t_env *ev, t_color c, t_vector s, t_vector e);
void				ft_print_square(t_color c, t_vector st, t_vector en,
								t_env *e);

/*
**	keyring/ft_keyring_ui_2.c
*/
void				ft_print_light_ui_4(t_env *e);
void				ft_print_light_ui_3(t_env *e);
void				ft_print_light_ui_2(t_env *e);
void				ft_print_light_ui(t_env *e);

/*
**	keyring/ft_keyring_ui.c
*/
void				ft_print_obj_ui(t_env *e);
void				ft_print_cam_ui_2(t_env *e);
void				ft_print_cam_ui(t_env *e);
void				ft_print_mm_ui(t_env *e);

/*
**	keyring/ft_keyring_utility.c
*/
void				ft_get_next_light(t_env *e);
t_light				*ft_get_light_at_nb(int nb, t_light *s);
void				ft_get_next_obj(t_env *e);
t_object			*ft_get_obj_at_nb(int nb, t_object *s);

/*
**	keyring/ft_keyring.c
*/
int					ft_get_cmd_interface(int press, int x, int y, t_env *e);
void				ft_print_pending_light(t_env *e, int mod);
void				ft_print_pending_obj(t_env *e, int mod);
int					ft_exec_cmd(int mod, t_env *e);
int					ft_click(int press, int x, int y, t_env *e);

/*
**	save.c
*/
int					save(t_env *e);

#endif
