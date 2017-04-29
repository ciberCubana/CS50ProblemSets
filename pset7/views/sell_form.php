<form action="sell.php" method="post">
    <fieldset>
        <div class="control-group">
            <select name="symbol">
                <option value=''></option>
                <?php
                    foreach($symbols as $s)
                    {
                        print("<option value='{$s["symbol"]}'>{$s["symbol"]}</option>\n");
                    }
                ?>
            </select>
        </div>
        </br>
        </br>
        
        
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                <span aria-hidden="true" class="glyphicon glyphicon-log-out"></span>
                Sell
            </button>
        </div>
    </fieldset>
</form>