/*****************************************************************************
 * preferences_widgets.h : wxWindows plugin for vlc
 *****************************************************************************
 * Copyright (C) 2000-2003 VideoLAN
 * $Id: preferences_widgets.h,v 1.1 2003/10/19 22:41:18 sigmunau Exp $
 *
 * Authors: Sigmund Augdal <sigmunau@idi.ntnu.no>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111, USA.
 *****************************************************************************/

class ConfigControl: public wxPanel
{
public:
    ConfigControl( wxWindow *parent );
    ~ConfigControl();
    wxSizer *Sizer();
    virtual int GetIntValue();
    virtual float GetFloatValue();
    virtual const char * GetPszValue();
protected:
    wxBoxSizer *sizer;
    wxStaticText *label;
private:
    int i_value;
    float f_value;
    char *psz_value;
};

class KeyConfigControl: public ConfigControl
{
public:
    KeyConfigControl( module_config_t *p_item, wxWindow *parent );
    ~KeyConfigControl();
    virtual int GetIntValue();
private:
    wxCheckBox *alt;
    wxCheckBox *ctrl;
    wxCheckBox *shift;
    wxComboBox *combo;
};

class ModuleConfigControl: public ConfigControl
{
public:
    ModuleConfigControl( intf_thread_t *p_intf, module_config_t *p_item,
                      wxWindow *parent );
    ~ModuleConfigControl();
    virtual const char *GetPszValue();
private:
    wxComboBox *combo;
};
    
class StringConfigControl: public ConfigControl
{
public:
    StringConfigControl( module_config_t *p_item, wxWindow *parent );
    ~StringConfigControl();
    virtual const char *GetPszValue();
private:
    wxTextCtrl *textctrl;
};

class StringListConfigControl: public ConfigControl
{
public:
    StringListConfigControl( module_config_t *p_item, wxWindow *parent );
    ~StringListConfigControl();
    virtual const char *GetPszValue();
private:
    wxComboBox *combo;
};

class FileConfigControl: public ConfigControl
{
public:
    FileConfigControl( module_config_t *p_item, wxWindow *parent );
    ~FileConfigControl();
    void FileConfigControl::OnBrowse( wxCommandEvent& );
    virtual const char *GetPszValue();
private:
    DECLARE_EVENT_TABLE()
    wxTextCtrl *textctrl;
    wxButton *browse;
    bool directory;
};

class IntegerConfigControl: public ConfigControl
{
public:
    IntegerConfigControl( module_config_t *p_item, wxWindow *parent );
    ~IntegerConfigControl();
    virtual int GetIntValue();
private:
    wxSpinCtrl *spin;
};

class RangedIntConfigControl: public ConfigControl
{
public:
    RangedIntConfigControl( module_config_t *p_item, wxWindow *parent );
    ~RangedIntConfigControl();
    virtual int GetIntValue();
private:
    wxSlider *slider;
};

class FloatConfigControl: public ConfigControl
{
public:
    FloatConfigControl( module_config_t *p_item, wxWindow *parent );
    ~FloatConfigControl();
    virtual float GetFloatValue();
private:
    wxTextCtrl *textctrl;
};

class BoolConfigControl: public ConfigControl
{
public:
    BoolConfigControl( module_config_t *p_item, wxWindow *parent );
    ~BoolConfigControl();
    virtual int GetIntValue();
private:
    wxCheckBox *checkbox;
};

