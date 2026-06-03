object FormDobrodosli: TFormDobrodosli
  Left = 0
  Top = 0
  Caption = 'Dobrodo'#353'li na IMiniDb'
  ClientHeight = 463
  ClientWidth = 657
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object GroupBoxGore: TGroupBox
    Left = 0
    Top = 0
    Width = 657
    Height = 273
    Align = alTop
    TabOrder = 0
    ExplicitWidth = 655
    object ImageLogo: TImage
      Left = 2
      Top = 17
      Width = 653
      Height = 299
      Align = alTop
      ExplicitTop = 0
      ExplicitWidth = 676
    end
    object Panel1: TPanel
      Left = 488
      Top = 105
      Width = 129
      Height = 104
      BevelOuter = bvNone
      TabOrder = 0
      object ButtonAPKInfo: TButton
        Left = 0
        Top = 25
        Width = 129
        Height = 27
        Align = alTop
        Caption = 'Informacije'
        TabOrder = 0
        OnClick = ButtonAPKInfoClick
      end
      object ButtonENG: TButton
        Left = 0
        Top = 77
        Width = 129
        Height = 25
        Align = alTop
        Caption = 'English'
        TabOrder = 1
        OnClick = ButtonENGClick
      end
      object ButtonHRV: TButton
        Left = 0
        Top = 52
        Width = 129
        Height = 25
        Align = alTop
        Caption = 'Hrvatski'
        TabOrder = 2
        OnClick = ButtonHRVClick
      end
      object ButtonMenu: TButton
        Left = 0
        Top = 0
        Width = 129
        Height = 25
        Align = alTop
        Caption = 'Izbornik'
        TabOrder = 3
        OnClick = ButtonMenuClick
      end
    end
  end
  object GroupBoxDolje: TGroupBox
    Left = 0
    Top = 279
    Width = 657
    Height = 184
    Align = alBottom
    TabOrder = 1
    ExplicitTop = 271
    ExplicitWidth = 655
    object Label1: TLabel
      Left = 302
      Top = 154
      Width = 48
      Height = 15
      Caption = 'v1.0 2026'
    end
    object ButtonPrijavaForm: TButton
      Left = 280
      Top = 71
      Width = 97
      Height = 34
      Caption = 'Prijavi se!'
      TabOrder = 0
      OnClick = ButtonPrijavaFormClick
    end
    object ButtonRegistracijaForm: TButton
      Left = 280
      Top = 32
      Width = 97
      Height = 33
      Caption = 'Registriraj se!'
      TabOrder = 1
      OnClick = ButtonRegistracijaFormClick
    end
  end
end
