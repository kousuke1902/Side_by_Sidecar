#pragma once

// キャラクターの基礎クラス
class Character
{

protected:

	int life; // 体力
	int pow; // 攻撃力
	int def; // 防御力
	  // ステータス効果
	Vec2 pos; // マスの座標
	Texture img; // キャラクタ画像
	Vec2 graph; // 描画座標
	String id; // キャラクタID
	String type; // キャラクタ属性
	int move; // 移動数
	bool death; // 死亡フラグ

public:

	// コンストラクタ
	Character(FilePath character_status_file, FilePath character_image_file, String set_id, String set_type, Vec2 set_pos)
	{
		// 設定ファイル確認
		const JSON json = JSON::Load(character_status_file);

		if (not json)
		{
			// 読込失敗時消滅させる
			death = true;
		}

		else
		{
			// 設定ファイルを読込
			life = json[U"life"].get<int32>();
			pow = json[U"pow"].get<int32>();
			def = json[U"def"].get<int32>();

			// 画像データの読込
			img = Texture{ character_image_file, TextureDesc::Mipped };

			// キャラクタID
			id = set_id;

			// キャラクタ属性
			type = set_type;

			// マス目の位置
			pos = set_pos;

			// 死亡フラグ
			death = false;

			// 描画座標
			graph = Vec2(0.0, 0.0);

			// ダイス残り移動数
			move = 0;

		}


	}

	// デストラクタ
	~Character(){}

	// ダメージ関数

	// エフェクト追加関数

	// サイコロ関数
	virtual int RolltheDice()
	{
		move = Random(1, 5);
		return 0;
	}

	// 描画関数
	int Draw()
	{

		return 0;
	}

};
