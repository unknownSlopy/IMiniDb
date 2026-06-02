object FormSviFilmovi: TFormSviFilmovi
  Left = 0
  Top = 0
  Align = alCustom
  Caption = 'MySQL'
  ClientHeight = 1005
  ClientWidth = 1247
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 24
    Top = 480
    Width = 3
    Height = 15
  end
  object LabelUkupnoFilmova: TLabel
    Left = 740
    Top = 521
    Width = 3
    Height = 15
  end
  object ButtonHRV: TButton
    Left = 1110
    Top = 8
    Width = 134
    Height = 34
    Caption = 'Hrvatski'
    TabOrder = 0
    OnClick = ButtonHRVClick
  end
  object ButtonENG: TButton
    Left = 1110
    Top = 48
    Width = 134
    Height = 34
    Caption = 'English'
    TabOrder = 1
    OnClick = ButtonENGClick
  end
  object GroupBoxGore: TGroupBox
    Left = 0
    Top = 0
    Width = 1247
    Height = 457
    Align = alTop
    TabOrder = 2
    object LabelListaZaGledanje: TLabel
      Left = 9
      Top = 20
      Width = 86
      Height = 15
      Caption = 'Lista za gledanje'
    end
    object LabelOmiljeniFilmoviNaslov: TLabel
      Left = 3
      Top = 20
      Width = 87
      Height = 15
      Caption = 'Omiljeni FIlmovi'
    end
    object listViewOFilmovi: TListView
      Left = 57
      Top = 65
      Width = 409
      Height = 267
      Columns = <
        item
          Caption = 'Naziv filma'
        end
        item
          Caption = 'Godina'
        end
        item
          Caption = 'Trajanje'
        end
        item
          Caption = 'Opis'
        end>
      HideSelection = False
      TabOrder = 0
      ViewStyle = vsReport
      OnSelectItem = listViewOFilmoviSelectItem
    end
    object GroupBoxOmiljeni: TGroupBox
      Left = 520
      Top = 65
      Width = 283
      Height = 257
      Align = alCustom
      Caption = 'Odaberi Film'
      TabOrder = 1
      object Label6: TLabel
        Left = 3
        Top = 51
        Width = 62
        Height = 15
        Caption = 'Naziv filma:'
      end
      object Label7: TLabel
        Left = 16
        Top = 85
        Width = 41
        Height = 15
        Caption = 'Godina:'
      end
      object Label8: TLabel
        Left = 13
        Top = 116
        Width = 44
        Height = 15
        Caption = 'Trajanje:'
      end
      object Label9: TLabel
        Left = 30
        Top = 151
        Width = 27
        Height = 15
        Caption = 'Opis:'
      end
      object ComboBoxFilmovi: TComboBox
        Left = 4
        Top = 19
        Width = 269
        Height = 23
        TabOrder = 0
        Text = 'FIlm'
        OnChange = ComboBoxFilmoviChange
      end
      object EditNoviNaziv: TEdit
        Left = 96
        Top = 48
        Width = 177
        Height = 23
        TabOrder = 1
      end
      object EditNovaGodina: TEdit
        Left = 96
        Top = 82
        Width = 177
        Height = 23
        TabOrder = 2
      end
      object EditNovoTrajanje: TEdit
        Left = 96
        Top = 113
        Width = 177
        Height = 23
        TabOrder = 3
      end
      object MemoOpisNovogFilma: TMemo
        Left = 108
        Top = 168
        Width = 172
        Height = 93
        Lines.Strings = (
          'MemoOpisNovogFilma')
        TabOrder = 4
      end
      object ButtonRecenzije: TButton
        Left = 7
        Top = 204
        Width = 95
        Height = 45
        Caption = 'Recenzije'
        TabOrder = 5
        OnClick = ButtonRecenzijeClick
      end
    end
    object GroupBoxOmiljeniKontrole: TGroupBox
      Left = 816
      Top = 64
      Width = 353
      Height = 217
      Caption = 'Omiljeni Filmovi'
      TabOrder = 2
      object LabelPrijavljeniKorisnik: TLabel
        Left = 2
        Top = 17
        Width = 349
        Height = 23
        Align = alTop
        Alignment = taRightJustify
        Caption = 'LabelPrijavljeniKorisnik'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -17
        Font.Name = 'Segoe UI'
        Font.Style = [fsBold]
        ParentFont = False
        ExplicitLeft = 1060
        ExplicitWidth = 187
      end
      object ButtonDodajNoviOFilm: TButton
        Left = 136
        Top = 25
        Width = 130
        Height = 58
        Caption = 'Dodaj novi'
        TabOrder = 0
        OnClick = ButtonDodajNoviOFilmClick
      end
      object ButtonUkloni: TButton
        Left = 0
        Top = 89
        Width = 130
        Height = 58
        Caption = 'Ukloni '
        TabOrder = 1
        OnClick = ButtonUkloniClick
      end
      object ButtonOmiljeniFilmovi: TButton
        Left = 0
        Top = 25
        Width = 130
        Height = 58
        Caption = 'Omiljeni Filmovi'
        TabOrder = 2
        OnClick = ButtonOmiljeniFilmoviClick
      end
    end
    object GroupBoxWatchlista: TGroupBox
      Left = 957
      Top = 216
      Width = 271
      Height = 217
      Caption = 'Watchlista'
      TabOrder = 3
      object ButtonPregledajListu: TButton
        Left = 3
        Top = 26
        Width = 130
        Height = 56
        Caption = 'Pregledaj Listu'
        TabOrder = 0
        OnClick = ButtonPregledajListuClick
      end
      object ButtonDodajWatchlistu: TButton
        Left = 138
        Top = 25
        Width = 130
        Height = 57
        Caption = 'Dodaj u Listu'
        TabOrder = 1
        OnClick = ButtonDodajWatchlistuClick
      end
    end
  end
  object GroupBoxDolje: TGroupBox
    Left = 0
    Top = 455
    Width = 1247
    Height = 550
    Align = alBottom
    TabOrder = 3
    object DBGridFilmoviBaza: TDBGrid
      Left = 0
      Top = 197
      Width = 885
      Height = 400
      DataSource = DataSourceFilm
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -12
      TitleFont.Name = 'Segoe UI'
      TitleFont.Style = []
      OnCellClick = DBGridFilmoviBazaCellClick
    end
    object GroupBoxPoster: TGroupBox
      Left = 891
      Top = 184
      Width = 354
      Height = 414
      TabOrder = 1
      object LabelPoster: TLabel
        Left = 2
        Top = 17
        Width = 350
        Height = 15
        Align = alTop
        Alignment = taCenter
        Caption = 'Poster'
        Color = clDarkorange
        ParentColor = False
        ExplicitWidth = 33
      end
      object DBImage1: TDBImage
        Left = 2
        Top = 32
        Width = 350
        Height = 380
        Align = alClient
        DataField = 'poster'
        DataSource = DataSourceFilm
        Proportional = True
        Stretch = True
        TabOrder = 0
      end
    end
    object GroupBoxDoljeKontrole: TGroupBox
      Left = 3
      Top = 25
      Width = 882
      Height = 166
      TabOrder = 2
      object Label2: TLabel
        Left = 273
        Top = 29
        Width = 103
        Height = 15
        Caption = 'Brzina preuzimanja:'
      end
      object LabelFilm: TLabel
        Left = 67
        Top = 114
        Width = 26
        Height = 15
        Caption = 'Film:'
      end
      object LabelProgres: TLabel
        Left = 580
        Top = 58
        Width = 68
        Height = 15
        Caption = 'LabelProgres'
      end
      object ComboBoxBrzina: TComboBox
        Left = 273
        Top = 50
        Width = 145
        Height = 23
        TabOrder = 0
        Items.Strings = (
          'Bez ograni'#269'enja'
          '256 KB/s'
          '512 KB/s'
          '1 MB/s')
      end
      object ButtonRESTBaza: TButton
        Left = 259
        Top = 104
        Width = 78
        Height = 41
        Caption = 'Dodaj u bazu'
        TabOrder = 1
        OnClick = ButtonRESTBazaClick
      end
      object editFilmRESTBaza: TEdit
        Left = 99
        Top = 111
        Width = 154
        Height = 23
        TabOrder = 2
        Text = 'editFilmRESTBaza'
      end
      object ProgressBar1: TProgressBar
        Left = 424
        Top = 52
        Width = 150
        Height = 21
        TabOrder = 3
      end
      object ToolBar1: TToolBar
        Left = 356
        Top = 104
        Width = 325
        Height = 41
        Align = alCustom
        ButtonHeight = 23
        ButtonWidth = 94
        Caption = 'ToolBar1'
        Customizable = True
        ShowCaptions = True
        TabOrder = 4
        object ToolButtonSQLSort: TToolButton
          Left = 0
          Top = 0
          Caption = 'Sortiraj'
          ImageIndex = 0
          OnClick = ToolButtonSQLSortClick
        end
        object ToolButtonSQLFilter: TToolButton
          Left = 94
          Top = 0
          Caption = 'Preporuka'
          ImageIndex = 1
          OnClick = ToolButtonSQLFilterClick
        end
        object ToolButtonSviPosteri: TToolButton
          Left = 188
          Top = 0
          Caption = 'Skini sve postere'
          ImageIndex = 2
          OnClick = ToolButtonSviPosteriClick
        end
      end
      object Button1: TButton
        Left = 758
        Top = 80
        Width = 75
        Height = 25
        Caption = 'TEST DLL'
        TabOrder = 5
        Visible = False
        OnClick = Button1Click
      end
    end
  end
  object XMLDocumentOmiljeniFilmovi: TXMLDocument
    FileName = 'C:\Users\Jan\Desktop\4sem\NTP\omiljeniFilmovi.xml'
    Left = 200
    Top = 152
  end
  object FDConnectionZaFilmove: TFDConnection
    Params.Strings = (
      'User_Name=root'
      'Database=iminidb'
      'Password=admin'
      'DriverID=MySQL')
    Connected = True
    LoginPrompt = False
    Left = 528
    Top = 936
  end
  object FDPhysMySQLDriverLink1: TFDPhysMySQLDriverLink
    VendorLib = 'C:\Users\Jan\Desktop\4sem\NTP\libmysql.dll'
    Left = 112
    Top = 704
  end
  object FDTableFilm: TFDTable
    Active = True
    IndexFieldNames = 'id'
    Connection = FDConnectionZaFilmove
    FetchOptions.AssignedValues = [evItems]
    ResourceOptions.AssignedValues = [rvEscapeExpand]
    TableName = 'iminidb.filmovi'
    Left = 112
    Top = 768
  end
  object DataSourceFilm: TDataSource
    DataSet = FDTableFilm
    Left = 112
    Top = 824
  end
  object FDQuerySelect: TFDQuery
    Active = True
    Connection = FDConnectionZaFilmove
    SQL.Strings = (
      
        'SELECT naslov,godina,trajanje,opis,zanr,redatelj,boxOffice,imdbR' +
        'ating,imdbVotes FROM Filmovi')
    Left = 216
    Top = 856
  end
  object FDQueryInsert: TFDQuery
    Connection = FDConnectionZaFilmove
    Left = 288
    Top = 704
  end
  object RESTClient1: TRESTClient
    Params = <>
    SynchronizedEvents = False
    Left = 440
    Top = 784
  end
  object RESTRequest1: TRESTRequest
    Client = RESTClient1
    Params = <>
    Response = RESTResponse1
    SynchronizedEvents = False
    Left = 512
    Top = 760
  end
  object RESTResponse1: TRESTResponse
    Left = 440
    Top = 712
  end
  object FDQuerySortGodina: TFDQuery
    Active = True
    Connection = FDConnectionZaFilmove
    SQL.Strings = (
      
        'SELECT naslov,godina,trajanje,opis,zanr,redatelj,boxOffice,imdbR' +
        'ating,imdbVotes,poster'
      'FROM Filmovi'
      'WHERE godina IS NOT NULL'
      'ORDER BY godina DESC')
    Left = 288
    Top = 784
  end
  object FDQueryFilterOcjena: TFDQuery
    Connection = FDConnectionZaFilmove
    SQL.Strings = (
      
        'SELECT naslov,godina,imdbRating,trajanje,opis,zanr,redatelj,boxO' +
        'ffice,imdbVotes,poster '
      'FROM Filmovi'
      'where imdbRating >= 8'
      'order by imdbRating desc')
    Left = 288
    Top = 856
  end
  object FDQueryBrojFilmova: TFDQuery
    Active = True
    Connection = FDConnectionZaFilmove
    SQL.Strings = (
      'SELECT COUNT(naslov)'
      'FROM filmovi')
    Left = 288
    Top = 912
  end
  object SymetricCodec: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    Left = 584
    Top = 712
    StreamCipherId = ''
    BlockCipherId = ''
    ChainId = ''
  end
end
