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
  object ButtonRegistracijaForm: TButton
    Left = 280
    Top = 304
    Width = 97
    Height = 33
    Caption = 'Registriraj se!'
    TabOrder = 0
  end
  object ButtonPrijavaForm: TButton
    Left = 280
    Top = 343
    Width = 97
    Height = 34
    Caption = 'Prijavi se!'
    TabOrder = 1
  end
  object GroupBoxGore: TGroupBox
    Left = 0
    Top = 0
    Width = 680
    Height = 273
    Align = alTop
    TabOrder = 2
    object ImageLogo: TImage
      Left = 2
      Top = 17
      Width = 676
      Height = 299
      Align = alTop
      ExplicitTop = 0
    end
    object ButtonENG: TButton
      Left = 528
      Top = 316
      Width = 75
      Height = 25
      Align = alRight
      Caption = 'English'
      TabOrder = 0
      OnClick = ButtonENGClick
      ExplicitLeft = 520
      ExplicitTop = 47
    end
    object ButtonHRV: TButton
      Left = 603
      Top = 316
      Width = 75
      Height = 25
      Align = alRight
      Caption = 'Hrvatski'
      TabOrder = 1
      OnClick = ButtonHRVClick
      ExplicitLeft = 520
      ExplicitTop = 16
    end
    object ButtonAPKInfo: TButton
      Left = 453
      Top = 316
      Width = 75
      Height = 27
      Align = alRight
      Caption = 'Informacije'
      TabOrder = 2
      ExplicitLeft = 520
      ExplicitTop = 78
    end
  end
end
