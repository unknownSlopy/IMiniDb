object FormDobrodosli: TFormDobrodosli
  Left = 0
  Top = 0
  Caption = 'Dobrodo'#353'li!'
  ClientHeight = 463
  ClientWidth = 680
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 294
    Top = 408
    Width = 48
    Height = 15
    Caption = 'v1.0 2026'
  end
  object ImageLogo: TImage
    Left = 0
    Top = 0
    Width = 680
    Height = 282
    Align = alTop
    ExplicitWidth = 629
  end
  object ButtonRegistracijaForm: TButton
    Left = 280
    Top = 304
    Width = 97
    Height = 33
    Caption = 'Registriraj se!'
    TabOrder = 0
  end
  object ButtonPrijavaForm: TButton
    Left = 294
    Top = 343
    Width = 75
    Height = 25
    Caption = 'Prijavi se!'
    TabOrder = 1
  end
  object ButtonHRV: TButton
    Left = 520
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Hrvatski'
    TabOrder = 2
    OnClick = ButtonHRVClick
  end
  object ButtonENG: TButton
    Left = 520
    Top = 47
    Width = 75
    Height = 25
    Caption = 'English'
    TabOrder = 3
    OnClick = ButtonENGClick
  end
end
