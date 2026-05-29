object FormPrijava: TFormPrijava
  Left = 0
  Top = 0
  Caption = 'Prijava'
  ClientHeight = 638
  ClientWidth = 1131
  Color = clBisque
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object ImageLogo: TImage
    Left = 280
    Top = 16
    Width = 361
    Height = 178
    AutoSize = True
  end
  object GroupBoxPrijava: TGroupBox
    Left = 368
    Top = 272
    Width = 361
    Height = 217
    TabOrder = 0
    object LabelKorImePrijava: TLabel
      Left = 64
      Top = 40
      Width = 81
      Height = 15
      Caption = 'Korisni'#269'ko ime:'
    end
    object LabelLozinkaPrijava: TLabel
      Left = 64
      Top = 80
      Width = 40
      Height = 15
      Caption = 'lozinka:'
    end
    object ButtonPrijava: TButton
      Left = 64
      Top = 152
      Width = 225
      Height = 25
      Caption = 'Prijavi se!'
      TabOrder = 0
      OnClick = ButtonPrijavaClick
    end
    object EditKorImePrijava: TEdit
      Left = 167
      Top = 37
      Width = 121
      Height = 23
      TabOrder = 1
    end
    object EditLozinkaPrijava: TEdit
      Left = 167
      Top = 74
      Width = 121
      Height = 23
      PasswordChar = '*'
      TabOrder = 2
    end
  end
  object ButtonHRV: TButton
    Left = 1016
    Top = 16
    Width = 99
    Height = 33
    Caption = 'Hrvatski'
    TabOrder = 1
    OnClick = ButtonHRVClick
  end
  object ButtonENG: TButton
    Left = 1016
    Top = 55
    Width = 99
    Height = 34
    Caption = 'English'
    TabOrder = 2
    OnClick = ButtonENGClick
  end
  object FDConnectionIMiniDB: TFDConnection
    Params.Strings = (
      'Database=iminidb'
      'User_Name=root'
      'Password=admin'
      'DriverID=MySQL')
    Connected = True
    LoginPrompt = False
    Left = 960
    Top = 264
  end
  object FDPhysMySQLDriverLink1: TFDPhysMySQLDriverLink
    VendorLib = 'C:\Users\Jan\Desktop\4sem\NTP\libmysql.dll'
    Left = 960
    Top = 168
  end
  object FDTableKorisnik: TFDTable
    Connection = FDConnectionIMiniDB
    TableName = 'iminidb.korisnik'
    Left = 792
    Top = 80
  end
  object DataSourceKorisnikPrijava: TDataSource
    DataSet = FDTableKorisnik
    Left = 800
    Top = 160
  end
  object FDQueryPrijava: TFDQuery
    Connection = FDConnectionIMiniDB
    Left = 808
    Top = 240
  end
end
