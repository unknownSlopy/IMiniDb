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
  object GroupBoxPrijavaLogo: TGroupBox
    Left = 200
    Top = 32
    Width = 529
    Height = 209
    TabOrder = 1
    object ImageLogo: TImage
      Left = 2
      Top = 17
      Width = 525
      Height = 190
      Align = alClient
      AutoSize = True
      ExplicitLeft = 202
      ExplicitTop = 39
      ExplicitWidth = 901
      ExplicitHeight = 178
    end
  end
  object GroupBoxSvojstva: TGroupBox
    Left = 992
    Top = 32
    Width = 100
    Height = 137
    TabOrder = 2
    object ButtonApkINFO: TButton
      Left = 3
      Top = 17
      Width = 96
      Height = 39
      Caption = 'Informacije '
      TabOrder = 0
      OnClick = ButtonApkINFOClick
    end
    object ButtonENG: TButton
      Left = 3
      Top = 62
      Width = 96
      Height = 33
      Caption = 'English'
      TabOrder = 1
      OnClick = ButtonENGClick
    end
    object ButtonHRV: TButton
      Left = 2
      Top = 102
      Width = 96
      Height = 33
      Align = alBottom
      Caption = 'Hrvatski'
      TabOrder = 2
      OnClick = ButtonHRVClick
      ExplicitLeft = 1
      ExplicitTop = 101
    end
  end
  object ButtonZatvori: TButton
    Left = 1098
    Top = 8
    Width = 33
    Height = 25
    Caption = 'X'
    TabOrder = 3
    OnClick = ButtonZatvoriClick
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
  object Codec1: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    Left = 928
    Top = 432
    StreamCipherId = ''
    BlockCipherId = ''
    ChainId = ''
  end
end
