/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_define.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:20:59 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:21:00 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_DEFINE_H
# define KEY_DEFINE_H

# define KEYPRESSMASK				(1L << 0)
# define KEYRELEASEMASK				(1L << 1)
# define BUTTON3MOTIONMASK			(1L << 10)
# define BUTTON4MOTIONMASK			(1L << 11)
# define BUTTON5MOTIONMASK			(1L << 12)
# define BUTTONMOTIONMASK			(1L << 13)
# define KEYMAPSTATEMASK			(1L << 14)
# define EXPOSUREMASK				(1L << 15)
# define VISIBILITYCHANGEMASK		(1L << 16)
# define STRUCTURENOTIFYMASK		(1L << 17)
# define RESIZEREDIRECTMASK			(1L << 18)
# define SUBSTRUCTURENOTIFYMASK		(1L << 19)
# define BUTTONPRESSMASK			(1L << 2)
# define SUBSTRUCTUREREDIRECTMASK	(1L << 20)
# define FOCUSCHANGEMASK			(1L << 21)
# define PROPERTYCHANGEMASK			(1L << 22)
# define COLORMAPCHANGEMASK			(1L << 23)
# define BUTTONRELEASEMASK			(1L << 3)
# define ENTERWINDOWMASK			(1L << 4)
# define LEAVEWINDOWMASK			(1L << 5)
# define POINTERMOTIONMASK			(1L << 6)
# define POINTERMOTIONHINTMASK		(1L << 7)
# define BUTTON1MOTIONMASK			(1L << 8)
# define BUTTON2MOTIONMASK			(1L << 9)

# define NOEVENTMASK		0L
# define FOCUSOUT			10
# define KEYMAPNOTIFY		11
# define EXPOSE				12
# define GRAPHICSEXPOSE		13
# define NOEXPOSE			14
# define VISIBILITYNOTIFY	15
# define CREATENOTIFY		16
# define DESTROYNOTIFY		17
# define UNMAPNOTIFY		18
# define MAPNOTIFY			19
# define KEYPRESS			2
# define MAPREQUEST			20
# define REPARENTNOTIFY		21
# define CONFIGURENOTIFY	22
# define CONFIGUREREQUEST	23
# define GRAVITYNOTIFY		24
# define RESIZEREQUEST		25
# define CIRCULATENOTIFY	26
# define CIRCULATEREQUEST	27
# define PROPERTYNOTIFY		28
# define SELECTIONCLEAR		29
# define KEYRELEASE			3
# define SELECTIONREQUEST	30
# define SELECTIONNOTIFY	31
# define COLORMAPNOTIFY		32
# define CLIENTMESSAGE		33
# define MAPPINGNOTIFY		34
# define LASTEVENT			35
# define BUTTONPRESS		4
# define BUTTONRELEASE		5
# define MOTIONNOTIFY		6
# define ENTERNOTIFY		7
# define LEAVENOTIFY		8
# define FOCUSIN			9

# define MOUSE_BUTTON_L		1
# define MOUSE_BUTTON_R		2
# define MOUSE_WHEEL_UP		4
# define MOUSE_WHEEL_DOWN	5

# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_ESC			53
# define KEY_TAB			48
# define KEY_FN				263
# define KEY_HOME			115
# define KEY_PGUP			116
# define KEY_PGDN			121
# define KEY_END			119
# define KEY_DEL			117
# define KEY_BACKSPACE		51
# define KEY_ENTER			36
# define KEY_SHIFT			257
# define KEY_CAPS			256
# define KEY_CTRL			258
# define KEY_ALT			259
# define KEY_F1				122
# define KEY_F2				120
# define KEY_F3				99
# define KEY_F4				118
# define KEY_F5				96
# define KEY_F6				97
# define KEY_F7				98
# define KEY_F8				100
# define KEY_F9				101
# define KEY_F10			109
# define KEY_F11			103
# define KEY_F12			111
# define KEY_COMMAND		259
# define KEY_MINUS			27
# define KEY_EQUAL			24
# define KEY_SPACE			49
# define KEY_0				29
# define KEY_1				18
# define KEY_2				19
# define KEY_3				20
# define KEY_4				21
# define KEY_5				23
# define KEY_6				22
# define KEY_7				26
# define KEY_8				28
# define KEY_9				25
# define KEY_A				0
# define KEY_B				11
# define KEY_C				8
# define KEY_D				2
# define KEY_E				14
# define KEY_F				3
# define KEY_G				5
# define KEY_H				4
# define KEY_I				34
# define KEY_J				38
# define KEY_K				40
# define KEY_L				37
# define KEY_M				46
# define KEY_N				45
# define KEY_O				31
# define KEY_P				35
# define KEY_Q				12
# define KEY_R				15
# define KEY_S				1
# define KEY_T				17
# define KEY_U				32
# define KEY_V				9
# define KEY_W				13
# define KEY_X				7
# define KEY_Y				16
# define KEY_Z				6
# define KEY_TIDLE			50
# define KEY_BRACKET_R		30
# define KEY_BRACKET_L		33

# define MOD_NONE			0
# define MOD_SHIFT			(1 << 0)
# define MOD_CAPS			(1 << 1)
# define MOD_CTRL			(1 << 2)
# define MOD_ALT			(1 << 3)

#endif
